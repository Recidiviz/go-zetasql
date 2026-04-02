//
// Minimal Laplace partition selection helpers matching the algorithms in
// https://github.com/google/differential-privacy (partition-selection.h),
// vendored so open-source ZetaSQL builds do not depend on an external
// "algorithms/partition-selection.h" include path.
//

#ifndef ZETASQL_PUBLIC_DIFFERENTIAL_PRIVACY_PARTITION_SELECTION_H_
#define ZETASQL_PUBLIC_DIFFERENTIAL_PRIVACY_PARTITION_SELECTION_H_

#include <cmath>
#include <cstdint>
#include "absl/status/status.h"
#include "absl/status/statusor.h"

namespace differential_privacy {

namespace zetasql_dp_partition_selection_internal {

inline absl::Status ValidateEpsilon(double epsilon) {
  if (!std::isfinite(epsilon) || epsilon <= 0) {
    return absl::InvalidArgumentError("epsilon must be finite and > 0");
  }
  return absl::OkStatus();
}

inline absl::Status ValidateDelta(double delta) {
  if (!std::isfinite(delta) || delta < 0 || delta > 1) {
    return absl::InvalidArgumentError("delta must be finite and in [0,1]");
  }
  return absl::OkStatus();
}

inline absl::Status ValidateMaxPartitionsContributed(int64_t max_pc) {
  if (max_pc <= 0) {
    return absl::InvalidArgumentError(
        "max_partitions_contributed must be positive");
  }
  return absl::OkStatus();
}

inline absl::StatusOr<double> CalculateAdjustedDelta(
    double delta, int64_t max_partitions_contributed) {
  if (auto s = ValidateDelta(delta); !s.ok()) return s;
  if (auto s = ValidateMaxPartitionsContributed(max_partitions_contributed);
      !s.ok()) {
    return s;
  }
  if (delta == 1) {
    return 1.0;
  }
  return -std::expm1(std::log1p(-delta) /
                     static_cast<double>(max_partitions_contributed));
}

inline absl::StatusOr<double> CalculateUnadjustedDelta(
    double adjusted_delta, int64_t max_partitions_contributed) {
  if (auto s = ValidateDelta(adjusted_delta); !s.ok()) return s;
  if (auto s = ValidateMaxPartitionsContributed(max_partitions_contributed);
      !s.ok()) {
    return s;
  }
  if (adjusted_delta == 1) {
    return 1.0;
  }
  return -std::expm1(static_cast<double>(max_partitions_contributed) *
                     std::log1p(-adjusted_delta));
}

inline double CalculateDiversity(double epsilon, int64_t l1_sensitivity) {
  return static_cast<double>(l1_sensitivity) / epsilon;
}

}  // namespace zetasql_dp_partition_selection_internal

// Mirrors differential_privacy::LaplacePartitionSelection static API used by
// zetasql/public/anonymization_utils.cc.
struct LaplacePartitionSelection {
  static absl::StatusOr<double> CalculateThreshold(double epsilon, double delta,
                                                   int64_t max_partitions_contributed) {
    using namespace zetasql_dp_partition_selection_internal;
    if (auto s = ValidateEpsilon(epsilon); !s.ok()) return s;
    if (auto s = ValidateDelta(delta); !s.ok()) return s;
    if (auto s = ValidateMaxPartitionsContributed(max_partitions_contributed);
        !s.ok()) {
      return s;
    }
    absl::StatusOr<double> adjusted_delta_or =
        CalculateAdjustedDelta(delta, max_partitions_contributed);
    if (!adjusted_delta_or.ok()) return adjusted_delta_or.status();
    double adjusted_delta = *adjusted_delta_or;
    const double diversity =
        CalculateDiversity(epsilon, max_partitions_contributed);
    if (delta > 0.5) {
      return 1 +
             diversity * std::log(2 * (1 - adjusted_delta));
    }
    return 1 - diversity * (std::log(2 * adjusted_delta));
  }

  static absl::StatusOr<double> CalculateDelta(double epsilon, double threshold,
                                               int64_t max_partitions_contributed) {
    using namespace zetasql_dp_partition_selection_internal;
    if (auto s = ValidateEpsilon(epsilon); !s.ok()) return s;
    if (auto s = ValidateMaxPartitionsContributed(max_partitions_contributed);
        !s.ok()) {
      return s;
    }
    if (!std::isfinite(threshold)) {
      return absl::InvalidArgumentError("threshold must be finite");
    }
    const double diversity =
        CalculateDiversity(epsilon, max_partitions_contributed);
    if (threshold < 1) {
      const double inner = std::exp((threshold - 1) / diversity) / 2;
      return CalculateUnadjustedDelta(1 - inner, max_partitions_contributed);
    }
    const double inner = std::exp((1 - threshold) / diversity) / 2;
    return CalculateUnadjustedDelta(inner, max_partitions_contributed);
  }
};

}  // namespace differential_privacy

#endif  // ZETASQL_PUBLIC_DIFFERENTIAL_PRIVACY_PARTITION_SELECTION_H_
