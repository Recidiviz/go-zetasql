package cord_rep_test_util

/*
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I../../../
*/
import "C"

import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-absl/base/config"
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-absl/base/raw_logging_internal"
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-absl/strings/cord_internal"
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-absl/strings/strings"
)
