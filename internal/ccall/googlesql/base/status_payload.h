//
// Copyright 2018 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef THIRD_PARTY_GOOGLESQL_GOOGLESQL_BASE_STATUS_PAYLOAD_H_
#define THIRD_PARTY_GOOGLESQL_GOOGLESQL_BASE_STATUS_PAYLOAD_H_

#include "absl/base/attributes.h"
#include "absl/status/status.h"
#include "absl/strings/cord.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/string_view.h"
#include "google/protobuf/descriptor.h"

namespace googlesql_base {

extern const absl::string_view kGoogleSqlTypeUrlPrefix;

// Return the type_url for encoding a Status payload of type T.
template <class T>
std::string GetTypeUrl() {
  const google::protobuf::Descriptor* d = T::descriptor();
  if (ABSL_PREDICT_TRUE(d != nullptr)) {
    return absl::StrCat(kGoogleSqlTypeUrlPrefix, d->full_name());
  }
  return absl::StrCat(kGoogleSqlTypeUrlPrefix, "googlesql.__missing_descriptor__");
}

// Attaches the given payload. This will overwrite any previous payload with
// the same type.
template <class T>
void AttachPayload(absl::Status* status, const T& payload) {
  absl::Cord serialized = absl::Cord(payload.SerializeAsString());
  const google::protobuf::Descriptor* d = T::descriptor();
  if (d == nullptr) {
    d = payload.GetDescriptor();
  }
  if (d == nullptr) {
    return;
  }
  status->SetPayload(absl::StrCat(kGoogleSqlTypeUrlPrefix, d->full_name()),
                     serialized);
}

}  // namespace googlesql_base

#endif  // THIRD_PARTY_GOOGLESQL_GOOGLESQL_BASE_STATUS_PAYLOAD_H_
