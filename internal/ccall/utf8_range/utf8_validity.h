// Copyright 2022 Google LLC
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#ifndef THIRD_PARTY_UTF8_RANGE_UTF8_VALIDITY_H_
#define THIRD_PARTY_UTF8_RANGE_UTF8_VALIDITY_H_

#include <cstddef>
#include <string_view>

namespace utf8_range {

// Returns true if the sequence of characters is a valid UTF-8 sequence.
// Uses std::string_view so the mangled symbol matches protobuf and Abseil
// (absl::string_view is typically an alias of std::string_view in C++17).
bool IsStructurallyValid(std::string_view str);

// Returns the length in bytes of the prefix of str that is all
// structurally valid UTF-8.
size_t SpanStructurallyValid(std::string_view str);

}  // namespace utf8_range

#endif  // THIRD_PARTY_UTF8_RANGE_UTF8_VALIDITY_H_
