// exportincgen synchronizes internal/ccall/**/export.inc with the include prelude in bind.cc.
//
// Usage (from repository root):
//
//	exportincgen              create export.inc only when missing (legacy default)
//	exportincgen -force      rewrite every export.inc that has a bind.cc prelude
//	exportincgen -check      verify preludes match; exit 1 on mismatch
package main

import (
	"errors"
	"flag"
	"fmt"
	"os"
	"path/filepath"

	"github.com/goccy/go-zetasql/internal/exportinc"
)

func main() {
	force := flag.Bool("force", false, "rewrite export.inc whenever bind.cc has a prelude")
	check := flag.Bool("check", false, "verify export.inc prelude matches bind.cc (no writes)")
	flag.Parse()

	if *force && *check {
		fmt.Fprintln(os.Stderr, "exportincgen: use only one of -force or -check")
		os.Exit(2)
	}

	root := filepath.Join("internal", "ccall")
	var checkErrs int
	if err := filepath.Walk(root, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}
		if info.IsDir() || filepath.Base(path) != "bind.cc" {
			return nil
		}
		dir := filepath.Dir(path)
		packageDir := filepath.ToSlash(dir)
		exportPath := filepath.Join(dir, "export.inc")

		bindContent, err := os.ReadFile(path)
		if err != nil {
			return err
		}

		if *check {
			exportContent, errRead := os.ReadFile(exportPath)
			if errRead != nil {
				if errors.Is(errRead, os.ErrNotExist) {
					_, errPrelude := exportinc.PreludeLinesFromBindCC(bindContent)
					if errors.Is(errPrelude, exportinc.ErrNoPrelude) {
						return nil
					}
					if errPrelude != nil {
						return errPrelude
					}
					return fmt.Errorf("%s: missing export.inc but bind.cc has prelude", exportPath)
				}
				return errRead
			}
			if err := exportinc.CheckBindVsExport(packageDir, bindContent, exportContent); err != nil {
				fmt.Fprintf(os.Stderr, "%s: %v\n", exportPath, err)
				checkErrs++
			}
			return nil
		}

		if !*force {
			if _, err := os.Stat(exportPath); err == nil {
				return nil
			}
		}

		out, err := exportinc.BuildFromBindCC(packageDir, bindContent)
		if err != nil {
			if errors.Is(err, exportinc.ErrNoPrelude) {
				return nil
			}
			return fmt.Errorf("%s: %w", path, err)
		}

		if err := os.WriteFile(exportPath, out, 0o600); err != nil {
			return err
		}
		return nil
	}); err != nil {
		fmt.Fprintf(os.Stderr, "%v\n", err)
		os.Exit(1)
	}
	if *check && checkErrs > 0 {
		os.Exit(1)
	}
}
