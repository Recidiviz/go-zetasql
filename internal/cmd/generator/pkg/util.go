package pkg

import (
	"fmt"
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

// mapBazelRootToCcallPath maps Bazel package roots to directory segments under
// internal/ccall/go-googlesql/.... Modern targets use googlesql/...; legacy
// BUILD files still reference zetasql/... for the same on-disk tree — map those
// to googlesql so generated #include paths use go-googlesql/... only.
func mapBazelRootToCcallPath(path string) string {
	switch {
	case path == "googlesql" || strings.HasPrefix(path, "googlesql/"):
		return path
	case path == "zetasql":
		return "googlesql"
	case strings.HasPrefix(path, "zetasql/"):
		return "googlesql/" + strings.TrimPrefix(path, "zetasql/")
	default:
		return path
	}
}

// LibPkgKey returns the canonical config key for a cc_library (googlesql/...), mapping legacy
// zetasql/ BUILD roots to googlesql/ for inject_replace_names and related YAML.
func LibPkgKey(basePkg, name string) string {
	return fmt.Sprintf("%s/%s", mapBazelRootToCcallPath(basePkg), name)
}

func goPkgPath(base, pkg string) string {
	base = mapBazelRootToCcallPath(base)
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

// tierBAbslRelPaths computes include/lib path segments for bind_tier_b_absl.go from a package
// directory under .../go-absl/<subpath>/ (outputDir may be absolute).
func tierBAbslRelPaths(outputDir string) (includeRel, libRel, anchorSuffix string, ok bool) {
	const mark = "go-absl"
	s := filepath.ToSlash(outputDir)
	i := strings.Index(s, mark+"/")
	if i < 0 {
		return "", "", "", false
	}
	sub := s[i+len(mark)+1:]
	sub = strings.TrimSuffix(sub, "/")
	if sub == "" {
		return "", "", "", false
	}
	parts := strings.Split(sub, "/")
	n := len(parts)
	includeRel = strings.Repeat("../", n+1)
	libRel = strings.Repeat("../", n) + "lib"
	anchorSuffix = strings.Join(parts, "_")
	return includeRel, libRel, anchorSuffix, true
}
