#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_ANALYZER_OPTIONS_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_ANALYZER_OPTIONS_EXPORT_H

#include "googlesql/public/analyzer_options.h"
// include sources
// options/type/proto type_annotation+wire_format .pb.cc amalgamation blocks are only in analyzer bind.cc; root links that package.
#include "googlesql/public/analyzer_options.cc"
// include dependencies
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/constant_evaluator/export.inc"
#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/rewriter_interface/export.inc"
#include "go-zetasql/public/time_zone_util/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/arena/export.inc"
#include "go-zetasql/base/check/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/parser/parser_mode/export.inc"
#include "go-zetasql/proto/options_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_builder/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/nullability/export.inc"
#include "go-absl/container/btree/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-absl/types/span/export.inc"

#endif
