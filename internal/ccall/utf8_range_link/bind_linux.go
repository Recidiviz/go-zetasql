package utf8_range_link

// Single translation unit for utf8_range so other CGO packages resolve
// utf8_range::IsStructurallyValid / SpanStructurallyValid while the default protobuf
// path links Bazel-built libprotobuf_cgo.a (which does not embed this .cc).

/*
#cgo CFLAGS: -x c++
#cgo CFLAGS: -std=c++20
#cgo CFLAGS: -I${SRCDIR}/../
#cgo CFLAGS: -I${SRCDIR}/../utf8_range
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I${SRCDIR}/../
#cgo CXXFLAGS: -I${SRCDIR}/../utf8_range
#cgo LDFLAGS: -lstdc++

#include "utf8_validity.cc"
*/
import "C"
