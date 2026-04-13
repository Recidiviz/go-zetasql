#ifndef INTERNAL_CCALL_GO_ABSL_CRC_CRC32C_EXPORT_H
#define INTERNAL_CCALL_GO_ABSL_CRC_CRC32C_EXPORT_H

#include "absl/crc/crc32c.h"
#include "absl/crc/internal/crc32c.h"
#include "absl/crc/internal/crc_memcpy.h"
// include sources
#include "absl/crc/crc32c.cc"
#include "absl/crc/internal/crc32c_inline.h"
#include "absl/crc/internal/crc_memcpy_fallback.cc"
#include "absl/crc/internal/crc_memcpy_x86_arm_combined.cc"
#include "absl/crc/internal/crc_non_temporal_memcpy.cc"
// include dependencies
#include "go-absl/crc/cpu_detect/export.inc"
#include "go-absl/crc/crc_internal/export.inc"
#include "go-absl/crc/non_temporal_memcpy/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/base/prefetch/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"

#endif
