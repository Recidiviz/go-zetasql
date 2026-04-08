#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_ANALYZER_OUTPUT_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_ANALYZER_OUTPUT_EXPORT_H

#include "googlesql/public/analyzer_output.h"
// include sources
// options/type/proto type_annotation+wire_format .pb.cc amalgamation blocks are only in analyzer bind.cc; root links that package.
#include "googlesql/public/analyzer_output.cc"
// include dependencies
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output_properties/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/base/arena/export.inc"
#include "go-zetasql/base/enum_utils/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/common/timer_util/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/proto/logging_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/time/time/export.inc"

#endif
