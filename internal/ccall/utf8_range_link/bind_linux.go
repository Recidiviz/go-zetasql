package utf8_range_link

// Single translation unit for utf8_range so protobuf amalgamations in other packages
// resolve utf8_range::IsStructurallyValid / SpanStructurallyValid without duplicating
// utf8_validity.cc inside go-protobuf/protobuf/export.inc.

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
