package pkg

import (
	"fmt"
	"io/fs"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strings"
)

// EnumerateGooglesqlOutputDirs returns relative paths (from internal/ccall) for every
// go-googlesql package the generator emits from googlesql/** BUILD files (cc_library and cc proto).
func (g *Generator) EnumerateGooglesqlOutputDirs() ([]string, error) {
	parsedFiles, err := g.createParsedFiles()
	if err != nil {
		return nil, err
	}
	seen := map[string]struct{}{}
	for _, pf := range parsedFiles {
		for _, lib := range pf.cclibs {
			rel := goPkgPath(lib.BasePkg, lib.Name)
			if strings.HasPrefix(rel, "go-googlesql") {
				seen[rel] = struct{}{}
			}
		}
		for _, lib := range pf.ccprotos {
			rel := goPkgPath(lib.BasePkg, lib.Name)
			if strings.HasPrefix(rel, "go-googlesql") {
				seen[rel] = struct{}{}
			}
		}
	}
	out := make([]string, 0, len(seen))
	for k := range seen {
		out = append(out, k)
	}
	sort.Strings(out)
	return out, nil
}

// OrphanGooglesqlPackageDirs returns directories under internal/ccall/go-googlesql that
// contain bind.cc but are not produced by EnumerateGooglesqlOutputDirs (stale packages).
func (g *Generator) OrphanGooglesqlPackageDirs() ([]string, error) {
	expected, err := g.EnumerateGooglesqlOutputDirs()
	if err != nil {
		return nil, err
	}
	want := map[string]struct{}{}
	for _, e := range expected {
		want[e] = struct{}{}
	}
	root := filepath.Join(ccallDir(), "go-googlesql")
	var orphans []string
	err = filepath.WalkDir(root, func(path string, d fs.DirEntry, err error) error {
		if err != nil {
			return err
		}
		if !d.IsDir() {
			return nil
		}
		if path == root {
			return nil
		}
		bindCC := filepath.Join(path, "bind.cc")
		if _, err := os.Stat(bindCC); err != nil {
			return nil
		}
		rel, err := filepath.Rel(ccallDir(), path)
		if err != nil {
			return err
		}
		rel = filepath.ToSlash(rel)
		if _, ok := want[rel]; !ok {
			orphans = append(orphans, rel)
		}
		return nil
	})
	if err != nil {
		return nil, err
	}
	sort.Strings(orphans)
	return orphans, nil
}

// staleFQDNGuard matches legacy include guards that used a zetasql_* FQDN prefix for whole-package
// symbols (e.g. zetasql_base_refcount_bind_cc). Does not match namespace token aliases such as
// `#define zetasql googlesql_pkg_...` or `#define zetasql_base ...` (no _bind_cc / _bridge_h suffix).
var staleFQDNGuard = regexp.MustCompile(`(?m)^#\s*(ifndef|define)\s+zetasql_[a-zA-Z0-9_]+_(bind_cc|bridge_h|extern_h)\s*$`)

// VerifyNoStaleZetasqlFQDNGuards returns an error if any file under internal/ccall/go-googlesql
// contains stale zetasql_* FQDN guards (not namespace-token defines).
func VerifyNoStaleZetasqlFQDNGuards() error {
	root := filepath.Join(ccallDir(), "go-googlesql")
	var bad []string
	err := filepath.WalkDir(root, func(path string, d fs.DirEntry, err error) error {
		if err != nil {
			return err
		}
		if d.IsDir() {
			return nil
		}
		base := filepath.Base(path)
		ext := filepath.Ext(path)
		if ext != ".cc" && ext != ".h" && ext != ".go" && ext != ".inc" {
			return nil
		}
		// Root amalgamation macro files intentionally define `zetasql` as a namespace token.
		if base == "root_analyzer_amalgamation_macros.inc" || base == "root_link_only_unified_macros.inc" {
			return nil
		}
		data, err := os.ReadFile(path)
		if err != nil {
			return err
		}
		if loc := staleFQDNGuard.FindIndex(data); loc != nil {
			bad = append(bad, path)
		}
		return nil
	})
	if err != nil {
		return err
	}
	if len(bad) > 0 {
		sort.Strings(bad)
		return fmt.Errorf("stale zetasql_* FQDN guards in: %s", strings.Join(bad, ", "))
	}
	return nil
}
