package main

import (
	"io"
	"io/fs"
	"os"
	"path/filepath"
	"runtime"
	"strings"

	cp "github.com/otiai10/copy"
)

func pkgDir() string {
	_, file, _, _ := runtime.Caller(0)
	return filepath.Dir(file)
}

func repoRootDir() string {
	path, _ := filepath.Abs(filepath.Join(pkgDir(), "..", "..", ".."))
	return path
}

func internalDir() string {
	return filepath.Join(repoRootDir(), "internal")
}

func ccallDir() string {
	return filepath.Join(internalDir(), "ccall")
}

func cacheDir() string {
	return filepath.Join(pkgDir(), "cache")
}

func externalDir() string {
	return filepath.Join(cacheDir(), "external")
}

func outDir() string {
	return filepath.Join(
		cacheDir(),
		"execroot",
		"com_google_zetasql",
		"bazel-out",
		"k8-fastbuild",
		"bin",
	)
}

func outExternalDir() string {
	return filepath.Join(outDir(), "external")
}

func appendLineIfMissing(path string, needle string, insertAfter string) error {
	data, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	content := string(data)
	if strings.Contains(content, needle) {
		return nil
	}
	idx := strings.Index(content, insertAfter)
	if idx == -1 {
		return nil
	}
	idx += len(insertAfter)
	content = content[:idx] + "\n" + needle + content[idx:]
	return os.WriteFile(path, []byte(content), 0o644)
}

func replaceIfMissing(path string, old string, new string) error {
	data, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	content := string(data)
	if strings.Contains(content, new) {
		return nil
	}
	if !strings.Contains(content, old) {
		return nil
	}
	content = strings.Replace(content, old, new, 1)
	return os.WriteFile(path, []byte(content), 0o644)
}

func applyPostCopyOverlays() error {
	if err := replaceIfMissing(
		filepath.Join(ccallDir(), "zetasql", "public", "functions", "date_time_util.cc"),
		`  return MakeEvalError() << "Converting timestamp interval " << interval
                         << " at " << TimestampScale_Name(interval_scale)
                         << " scale to " << TimestampScale_Name(output_scale)
                         << " scale causes overflow";
}`,
		`  return MakeEvalError() << "Converting timestamp interval " << interval
                         << " at " << TimestampScale_Name(interval_scale)
                         << " scale to " << TimestampScale_Name(output_scale)
                         << " scale causes overflow";
}
#undef FCT`,
	); err != nil {
		return err
	}
	if err := appendLineIfMissing(
		filepath.Join(ccallDir(), "zetasql", "public", "types", "BUILD"),
		`        "//zetasql/public/proto:wire_format_annotation_cc_proto",`,
		`        "//zetasql/public/functions:rounding_mode_cc_proto",`,
	); err != nil {
		return err
	}
	if err := replaceIfMissing(
		filepath.Join(ccallDir(), "icu", "common", "bytesinkutil.h"),
		`#include "unicode/utypes.h"
`,
		`#ifndef GO_ZETASQL_ICU_COMMON_BYTESINKUTIL_H_
#define GO_ZETASQL_ICU_COMMON_BYTESINKUTIL_H_

#include "unicode/utypes.h"
`,
	); err != nil {
		return err
	}
	if err := replaceIfMissing(
		filepath.Join(ccallDir(), "icu", "common", "bytesinkutil.h"),
		"U_NAMESPACE_END\n",
		`U_NAMESPACE_END

#endif  // GO_ZETASQL_ICU_COMMON_BYTESINKUTIL_H_
`,
	); err != nil {
		return err
	}
	return nil
}

var copyExternalLibMap = map[string]string{
	"icu/source":                "icu",
	"json":                      "json",
	"flex":                      "flex",
	"com_google_absl/absl":      "absl",
	"com_google_protobuf/src":   "protobuf",
	"com_googlesource_code_re2": "re2",
	"com_google_cc_differential_privacy/algorithms": "algorithms",
	"com_google_cc_differential_privacy/base":       "base",
	"com_google_cc_differential_privacy/proto":      "proto",
	"com_google_differential_privacy/proto":         "proto",
}

var copyOutExternalLibMap = map[string]string{
	"com_google_googleapis":                 "googleapis",
	"com_google_differential_privacy/proto": "proto",
}

func main() {
	opt := cp.Options{
		AddPermission: 0o755,
		Skip: func(src string) (bool, error) {
			info, err := os.Stat(src)
			if err != nil {
				return false, err
			}
			if info.IsDir() {
				return false, nil
			}
			switch filepath.Base(src) {
			case "BUILD", "BUILD.bazel":
				return false, nil
			}
			switch filepath.Ext(src) {
			case ".h", ".hh", ".cc", ".c", ".inc":
				return false, nil
			}
			return true, nil
		},
	}
	for src, dst := range copyExternalLibMap {
		cp.Copy(
			filepath.Join(externalDir(), src),
			filepath.Join(ccallDir(), dst),
			opt,
		)
	}
	for src, dst := range copyOutExternalLibMap {
		cp.Copy(
			filepath.Join(outExternalDir(), src),
			filepath.Join(ccallDir(), dst),
			opt,
		)
	}
	cp.Copy(
		filepath.Join(pkgDir(), "zetasql", "zetasql"),
		filepath.Join(ccallDir(), "zetasql"),
		opt,
	)
	if err := filepath.Walk(
		filepath.Join(outDir(), "zetasql"),
		func(path string, info fs.FileInfo, err error) error {
			if info.IsDir() {
				return nil
			}
			if (info.Mode() & fs.ModeSymlink) != 0 {
				return nil
			}
			fileName := filepath.Base(path)
			lastChar := fileName[len(fileName)-1]
			if lastChar == 'h' || lastChar == 'c' {
				idx := strings.LastIndex(path, "zetasql")
				trimmedPath := path[idx:]
				dstFile := filepath.Join(ccallDir(), trimmedPath)
				src, err := os.Open(path)
				if err != nil {
					return err
				}
				defer src.Close()
				if err := os.Remove(dstFile); err != nil && !os.IsNotExist(err) {
					return err
				}
				dst, err := os.Create(dstFile)
				if err != nil {
					return err
				}
				defer dst.Close()
				if _, err := io.Copy(dst, src); err != nil {
					return err
				}
			}
			return nil
		},
	); err != nil {
		panic(err)
	}
	if err := applyPostCopyOverlays(); err != nil {
		panic(err)
	}
}
