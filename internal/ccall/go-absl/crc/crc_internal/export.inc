#ifndef INTERNAL_CCALL_GO_ABSL_CRC_CRC_INTERNAL_EXPORT_H
#define INTERNAL_CCALL_GO_ABSL_CRC_CRC_INTERNAL_EXPORT_H

#include "absl/crc/internal/crc.h"
#include "absl/crc/internal/crc32_x86_arm_combined_simd.h"
// include sources
#include "absl/crc/internal/crc.cc"
#include "absl/crc/internal/crc_internal.h"
#include "absl/crc/internal/crc_x86_arm_combined.cc"
// include dependencies
#include "go-absl/crc/cpu_detect/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/dynamic_annotations/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/base/prefetch/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/numeric/bits/export.inc"

#endif
