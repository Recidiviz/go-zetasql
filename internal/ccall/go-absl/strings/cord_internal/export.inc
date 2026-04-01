#ifndef INTERNAL_CCALL_GO_ABSL_STRINGS_CORD_INTERNAL_EXPORT_H
#define INTERNAL_CCALL_GO_ABSL_STRINGS_CORD_INTERNAL_EXPORT_H

#include "absl/strings/internal/cord_data_edge.h"
#include "absl/strings/internal/cord_internal.h"
#include "absl/strings/internal/cord_rep_btree.h"
#include "absl/strings/internal/cord_rep_btree_navigator.h"
#include "absl/strings/internal/cord_rep_btree_reader.h"
#include "absl/strings/internal/cord_rep_consume.h"
#include "absl/strings/internal/cord_rep_crc.h"
#include "absl/strings/internal/cord_rep_flat.h"
#include "absl/strings/internal/cord_rep_ring.h"
#include "absl/strings/internal/cord_rep_ring_reader.h"
// include sources
#include "absl/strings/internal/cord_internal.cc"
#include "absl/strings/internal/cord_rep_btree.cc"
#include "absl/strings/internal/cord_rep_btree_navigator.cc"
#include "absl/strings/internal/cord_rep_btree_reader.cc"
#include "absl/strings/internal/cord_rep_consume.cc"
#include "absl/strings/internal/cord_rep_crc.cc"
#include "absl/strings/internal/cord_rep_ring.cc"
// include dependencies
#include "go-absl/strings/strings/export.inc"
#include "go-absl/base/base_internal/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/base/throw_delegate/export.inc"
#include "go-absl/container/compressed_tuple/export.inc"
#include "go-absl/container/container_memory/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/container/layout/export.inc"
#include "go-absl/crc/crc_cord_state/export.inc"
#include "go-absl/functional/function_ref/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/types/span/export.inc"

#endif
