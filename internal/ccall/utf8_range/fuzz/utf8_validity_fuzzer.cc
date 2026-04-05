// Copyright 2022 Google LLC
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include <string_view>

#include "utf8_validity.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  std::string_view buf(reinterpret_cast<const char *>(data), size);
  utf8_range::IsStructurallyValid(buf);
  utf8_range::SpanStructurallyValid(buf);
  return 0;
}
