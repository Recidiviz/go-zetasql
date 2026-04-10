package utf8_range_link

// Single translation unit for utf8_range so other CGO packages resolve
// utf8_range::IsStructurallyValid / SpanStructurallyValid while the default protobuf
// path links Bazel-built libprotobuf_cgo.a (which does not embed this .cc).
//
// Linux must use the same libc++ as libprotobuf_cgo.a (Bazel LLVM). Linking -lstdc++
// loads libstdc++.so alongside libc++-linked prebuilts and corrupts std:: types (e.g.
// absl::flat_hash_map / DescriptorPool static init SIGSEGV).

/*
#cgo CFLAGS: -x c++
#cgo CFLAGS: -std=c++20
#cgo CFLAGS: -I${SRCDIR}/../
#cgo CFLAGS: -I${SRCDIR}/../utf8_range
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -stdlib=libc++
#cgo CXXFLAGS: -I${SRCDIR}/../
#cgo CXXFLAGS: -I${SRCDIR}/../utf8_range
#cgo LDFLAGS: -L${SRCDIR}/../go-protobuf/protobuf/lib
#cgo LDFLAGS: -Wl,--start-group -l:libcxx_prebuilt.a -l:libcxxabi_prebuilt.a -Wl,--end-group -ldl

#include "utf8_validity.cc"
*/
import "C"
