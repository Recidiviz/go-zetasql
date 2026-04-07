package pkg

import (
	"os"
	"path/filepath"
	"runtime"
	"strings"
)

func pkgDir() string {
	_, file, _, _ := runtime.Caller(0)
	return filepath.Dir(file)
}

func repoRootDir() string {
	path, _ := filepath.Abs(filepath.Join(pkgDir(), "..", "..", "..", ".."))
	return path
}

func internalDir() string {
	return filepath.Join(repoRootDir(), "internal")
}

func ccallDir() string {
	return filepath.Join(internalDir(), "ccall")
}

func toSourceDirFromLibName(lib string) string {
	return filepath.Join(ccallDir(), lib)
}

func existsFile(path string) bool {
	_, err := os.Stat(path)
	return err == nil
}

// stripBazelExternalPrefix removes a leading '@' from a single Bazel external
// workspace segment (e.g. "@json" -> "json"). See build_file_parser.go handling
// of deps that are only "@xyz".
func stripBazelExternalPrefix(seg string) string {
	return strings.TrimPrefix(seg, "@")
}

// mapGooglesqlToZetasqlGoImportTree maps Bazel paths under googlesql/ to the stable
// internal/ccall/go-zetasql/... layout. Upstream renamed zetasql→googlesql; Go import paths
// and the ccall folder prefix remain go-zetasql.
func mapGooglesqlToZetasqlGoImportTree(path string) string {
	if path == "googlesql" {
		return "zetasql"
	}
	if strings.HasPrefix(path, "googlesql/") {
		return "zetasql/" + strings.TrimPrefix(path, "googlesql/")
	}
	return path
}

func goPkgPath(base, pkg string) string {
	base = mapGooglesqlToZetasqlGoImportTree(base)
	newPath := []string{}
	for _, path := range strings.Split(base, "/") {
		path = stripBazelExternalPrefix(path)
		if path == "" {
			continue
		}
		if path == "internal" {
			newPath = append(newPath, "go_internal")
		} else {
			newPath = append(newPath, path)
		}
	}
	pkg = stripBazelExternalPrefix(pkg)
	baseJoined := filepath.Join(newPath...)
	if baseJoined == "" {
		return "go-" + pkg
	}
	joined := filepath.Join(baseJoined, pkg)
	// @boringssl//boringssl maps to a single go-boringssl tree (export.inc at root), not go-boringssl/boringssl.
	if joined == "boringssl/boringssl" {
		return "go-boringssl"
	}
	return "go-" + joined
}

func normalizeGoPkgPath(name string) string {
	splitted := strings.Split(name, "/")
	for i := range splitted {
		splitted[i] = stripBazelExternalPrefix(splitted[i])
	}
	base := filepath.Join(splitted[:len(splitted)-1]...)
	pkg := splitted[len(splitted)-1]
	return goPkgPath(base, pkg)
}
