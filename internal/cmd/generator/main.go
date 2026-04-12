package main

import (
	"embed"
	"flag"
	"fmt"
	"log"

	"github.com/vantaboard/go-googlesql/internal/cmd/generator/pkg"
)

//go:embed templates/*.tmpl
var templates embed.FS

//go:embed config.yaml
var configYAML []byte

//go:embed bridge.yaml
var bridgeYAML []byte

//go:embed import.yaml
var importYAML []byte

func main() {
	listPackages := flag.Bool("list-packages", false, "print go-googlesql output dirs from BUILD scan and exit")
	orphanDirs := flag.Bool("orphan-dirs", false, "print stale go-googlesql package dirs (have bind.cc but not in BUILD scan) and exit")
	verifyFQDN := flag.Bool("verify-googlesql-fqdn", false, "fail if any stale legacy zetasql_* FQDN include guards remain under go-googlesql (pre-GoogleSQL normalization)")
	flag.Parse()

	if err := run(*listPackages, *orphanDirs, *verifyFQDN); err != nil {
		log.Fatalf("%+v\n", err)
	}
}

func run(listPackages, orphanDirs, verifyFQDN bool) error {
	cfg, err := pkg.LoadConfig(configYAML)
	if err != nil {
		return err
	}
	bridge, err := pkg.LoadBridge(bridgeYAML)
	if err != nil {
		return err
	}
	importSymbols, err := pkg.LoadImport(importYAML)
	if err != nil {
		return err
	}
	generator := pkg.NewGenerator(cfg, bridge, importSymbols, templates)

	if listPackages {
		dirs, err := generator.EnumerateGooglesqlOutputDirs()
		if err != nil {
			return err
		}
		for _, d := range dirs {
			fmt.Println(d)
		}
		return nil
	}
	if orphanDirs {
		orphans, err := generator.OrphanGooglesqlPackageDirs()
		if err != nil {
			return err
		}
		for _, o := range orphans {
			fmt.Println(o)
		}
		return nil
	}
	if verifyFQDN {
		if err := pkg.VerifyNoStaleGooglesqlFQDNGuards(); err != nil {
			return err
		}
		fmt.Println("ok: no stale legacy zetasql_* FQDN guards under go-googlesql")
		return nil
	}

	if err := generator.Generate(); err != nil {
		return err
	}
	if err := pkg.VerifyNoStaleGooglesqlFQDNGuards(); err != nil {
		return fmt.Errorf("generator produced stale legacy zetasql_* FQDN guards: %w", err)
	}
	return nil
}
