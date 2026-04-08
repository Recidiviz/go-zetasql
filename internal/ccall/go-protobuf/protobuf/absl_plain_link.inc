#ifndef GO_GOOGLESQL_GO_PROTOBUF_ABSL_PLAIN_LINK_INC_
#define GO_GOOGLESQL_GO_PROTOBUF_ABSL_PLAIN_LINK_INC_

// Plain `absl::` symbols for protobuf in this CGO TU (single amalgamation).
// Additional Abseil sources are compiled as separate .cc files in
// absl_plain_wrappers/ so anonymous-namespace helpers do not collide in one TU.
//
// absl/numeric/int128.cc is omitted: it conflicts with google/protobuf/stubs/int128.cc.
#include "absl/base/internal/raw_logging.cc"
#include "absl/hash/internal/city.cc"
#include "absl/hash/internal/low_level_hash.cc"
#include "absl/hash/internal/hash.cc"
#include "absl/container/internal/raw_hash_set.cc"

#endif  // GO_GOOGLESQL_GO_PROTOBUF_ABSL_PLAIN_LINK_INC_
