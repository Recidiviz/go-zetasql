// Minimal shim for Abseil nullability (go-googlesql vendored absl may omit this
// header). Matches the public aliases used by GoogleSQL analyzer sources.
#ifndef ABSL_BASE_NULLABILITY_H_
#define ABSL_BASE_NULLABILITY_H_

namespace absl {

template <typename T>
using Nullable = T;

template <typename T>
using Nonnull = T;

template <typename T>
using NullabilityUnknown = T;

}  // namespace absl

#define ABSL_NULLABILITY_COMPATIBLE

#endif  // ABSL_BASE_NULLABILITY_H_
