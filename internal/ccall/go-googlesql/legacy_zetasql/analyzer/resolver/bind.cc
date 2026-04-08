
#ifndef googlesql_legacy_zetasql_analyzer_resolver_bind_cc
#define googlesql_legacy_zetasql_analyzer_resolver_bind_cc

// switch namespace
#define differential_privacy googlesql_legacy_zetasql_analyzer_resolver_differential_privacy
#define googlesql googlesql_legacy_zetasql_analyzer_resolver_googlesql
#define googlesql_base googlesql_legacy_zetasql_analyzer_resolver_googlesql_base
#define googlesql_bison_parser googlesql_legacy_zetasql_analyzer_resolver_googlesql_bison_parser
#define re2 googlesql_legacy_zetasql_analyzer_resolver_re2
#define AbslInternalSleepFor googlesql_legacy_zetasql_analyzer_resolver_AbslInternalSleepFor
#define AbslInternalReportFatalUsageError googlesql_legacy_zetasql_analyzer_resolver_AbslInternalReportFatalUsageError
#define AbslInternalMutexYield googlesql_legacy_zetasql_analyzer_resolver_AbslInternalMutexYield
#define AbslInternalPerThreadSemPost googlesql_legacy_zetasql_analyzer_resolver_AbslInternalPerThreadSemPost
#define AbslInternalPerThreadSemWait googlesql_legacy_zetasql_analyzer_resolver_AbslInternalPerThreadSemWait
#define AbslContainerInternalSampleEverything googlesql_legacy_zetasql_analyzer_resolver_AbslContainerInternalSampleEverything
#define AbslInternalSpinLockDelay googlesql_legacy_zetasql_analyzer_resolver_AbslInternalSpinLockDelay
#define AbslInternalSpinLockWake googlesql_legacy_zetasql_analyzer_resolver_AbslInternalSpinLockWake
#define AbslInternalAnnotateIgnoreReadsBegin googlesql_legacy_zetasql_analyzer_resolver_AbslInternalAnnotateIgnoreReadsBegin
#define AbslInternalAnnotateIgnoreReadsEnd googlesql_legacy_zetasql_analyzer_resolver_AbslInternalAnnotateIgnoreReadsEnd
#define AbslInternalGetFileMappingHint googlesql_legacy_zetasql_analyzer_resolver_AbslInternalGetFileMappingHint
#define GoogleSqlalloc googlesql_legacy_zetasql_analyzer_resolver_GoogleSqlalloc
#define GoogleSqlfree googlesql_legacy_zetasql_analyzer_resolver_GoogleSqlfree
#define GoogleSqlrealloc googlesql_legacy_zetasql_analyzer_resolver_GoogleSqlrealloc
#define FLAGS_nooutput_asc_explicitly googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nooutput_asc_explicitly
#define FLAGS_nogooglesql_use_customized_flex_istream googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nogooglesql_use_customized_flex_istream
#define FLAGS_output_asc_explicitly googlesql_legacy_zetasql_analyzer_resolver_FLAGS_output_asc_explicitly
#define FLAGS_googlesql_use_customized_flex_istream googlesql_legacy_zetasql_analyzer_resolver_FLAGS_googlesql_use_customized_flex_istream
#define FLAGS_googlesql_type_factory_nesting_depth_limit googlesql_legacy_zetasql_analyzer_resolver_FLAGS_googlesql_type_factory_nesting_depth_limit
#define FLAGS_googlesql_read_proto_field_optimized_path googlesql_legacy_zetasql_analyzer_resolver_FLAGS_googlesql_read_proto_field_optimized_path
#define FLAGS_googlesql_format_max_output_width googlesql_legacy_zetasql_analyzer_resolver_FLAGS_googlesql_format_max_output_width
#define FLAGS_googlesql_min_length_required_for_edit_distance googlesql_legacy_zetasql_analyzer_resolver_FLAGS_googlesql_min_length_required_for_edit_distance
#define FLAGS_googlesql_simple_iterator_call_time_now_rows_period googlesql_legacy_zetasql_analyzer_resolver_FLAGS_googlesql_simple_iterator_call_time_now_rows_period
#define FLAGS_nogooglesql_type_factory_nesting_depth_limit googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nogooglesql_type_factory_nesting_depth_limit
#define FLAGS_nogooglesql_read_proto_field_optimized_path googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nogooglesql_read_proto_field_optimized_path
#define FLAGS_nogooglesql_format_max_output_width googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nogooglesql_format_max_output_width
#define FLAGS_nogooglesql_min_length_required_for_edit_distance googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nogooglesql_min_length_required_for_edit_distance
#define FLAGS_nogooglesql_simple_iterator_call_time_now_rows_period googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nogooglesql_simple_iterator_call_time_now_rows_period
#define FLAGS_googlesql_enough_stack_bytes googlesql_legacy_zetasql_analyzer_resolver_FLAGS_googlesql_enough_stack_bytes
#define FLAGS_nogooglesql_enough_stack_bytes googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nogooglesql_enough_stack_bytes
#define FLAGS_googlesql_canonicalize_signed_zero_to_string googlesql_legacy_zetasql_analyzer_resolver_FLAGS_googlesql_canonicalize_signed_zero_to_string
#define FLAGS_nogooglesql_canonicalize_signed_zero_to_string googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nogooglesql_canonicalize_signed_zero_to_string
#define FLAGS_googlesql_default_error_message_stability googlesql_legacy_zetasql_analyzer_resolver_FLAGS_googlesql_default_error_message_stability
#define FLAGS_nogooglesql_default_error_message_stability googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nogooglesql_default_error_message_stability
#define FLAGS_googlesql_redact_error_messages_for_tests googlesql_legacy_zetasql_analyzer_resolver_FLAGS_googlesql_redact_error_messages_for_tests
#define FLAGS_nogooglesql_redact_error_messages_for_tests googlesql_legacy_zetasql_analyzer_resolver_FLAGS_nogooglesql_redact_error_messages_for_tests
#define GoogleSqlFlexTokenizerBase googlesql_legacy_zetasql_analyzer_resolver_GoogleSqlFlexTokenizerBase
#define GoogleSqlFlexLexer googlesql_legacy_zetasql_analyzer_resolver_GoogleSqlFlexLexer
#define UCaseMap googlesql_legacy_zetasql_analyzer_resolver_UCaseMap

#define GO_EXPORT(def) export_googlesql_legacy_zetasql_analyzer_resolver_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)

// bridge_cc.inc uses GoSlice; bridge.inc includes _cgo_export.h again for exported symbols.
#include "_cgo_export.h"


// Descriptor table identifiers for googlesql/public/options.proto (see googlesql/public/analyzer amalgamation).
#define googlesql_2fpublic_2foptions_2eproto googlesql_public_analyzer_googlesql_2fpublic_2foptions_2eproto
#define descriptor_table_googlesql_2fpublic_2foptions_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2foptions_2eproto
#define TableStruct_googlesql_2fpublic_2foptions_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2foptions_2eproto
// Descriptor table identifiers for googlesql/public/type.proto (same single-owner TU as options.pb.cc).
#define googlesql_2fpublic_2ftype_2eproto googlesql_public_analyzer_googlesql_2fpublic_2ftype_2eproto
#define descriptor_table_googlesql_2fpublic_2ftype_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2ftype_2eproto
#define TableStruct_googlesql_2fpublic_2ftype_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2ftype_2eproto
// googlesql/public/proto/wire_format_annotation.proto (paired with public/proto/type_annotation in analyzer).
#define googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto googlesql_public_analyzer_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define descriptor_table_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define TableStruct_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
// googlesql/public/proto/type_annotation.proto (extends google.protobuf.FieldOptions; single-owner TU).
#define googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto googlesql_public_analyzer_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define descriptor_table_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define TableStruct_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto
// include headers
//#define private public
#include "googlesql/legacy_zetasql/analyzer/analytic_function_resolver.h"
#include "googlesql/legacy_zetasql/analyzer/column_cycle_detector.h"
#include "googlesql/legacy_zetasql/analyzer/expr_resolver_helper.h"
#include "googlesql/legacy_zetasql/analyzer/function_resolver.h"
#include "googlesql/legacy_zetasql/analyzer/graph_expr_resolver_helper.h"
#include "googlesql/legacy_zetasql/analyzer/graph_query_resolver.h"
#include "googlesql/legacy_zetasql/analyzer/graph_stmt_resolver.h"
#include "googlesql/legacy_zetasql/analyzer/named_argument_info.h"
#include "googlesql/legacy_zetasql/analyzer/query_resolver_helper.h"
#include "googlesql/legacy_zetasql/analyzer/resolver.h"
//#undef private

// include sources
#include "googlesql/legacy_zetasql/analyzer/analytic_function_resolver.cc"
#include "googlesql/legacy_zetasql/analyzer/column_cycle_detector.cc"
#include "googlesql/legacy_zetasql/analyzer/expr_resolver_helper.cc"
#include "googlesql/legacy_zetasql/analyzer/function_resolver.cc"
#include "googlesql/legacy_zetasql/analyzer/graph_expr_resolver_helper.cc"
#include "googlesql/legacy_zetasql/analyzer/graph_query_resolver.cc"
#include "googlesql/legacy_zetasql/analyzer/graph_stmt_resolver.cc"
#include "googlesql/legacy_zetasql/analyzer/query_resolver_helper.cc"
#include "googlesql/legacy_zetasql/analyzer/recursive_queries.cc"
#include "googlesql/legacy_zetasql/analyzer/recursive_queries.h"
#include "googlesql/legacy_zetasql/analyzer/resolver.cc"
#include "googlesql/legacy_zetasql/analyzer/resolver_alter_stmt.cc"
#include "googlesql/legacy_zetasql/analyzer/resolver_common_inl.h"
#include "googlesql/legacy_zetasql/analyzer/resolver_dml.cc"
#include "googlesql/legacy_zetasql/analyzer/resolver_expr.cc"
#include "googlesql/legacy_zetasql/analyzer/resolver_query.cc"
#include "googlesql/legacy_zetasql/analyzer/resolver_stmt.cc"

// include dependencies
#include "go-zetasql/legacy_zetasql/analyzer/annotation_propagator/export.inc"
#include "go-zetasql/legacy_zetasql/analyzer/container_hash_equals/export.inc"
#include "go-zetasql/legacy_zetasql/analyzer/expr_matching_helpers/export.inc"
#include "go-zetasql/legacy_zetasql/analyzer/filter_fields_path_validator/export.inc"
#include "go-zetasql/legacy_zetasql/analyzer/function_signature_matcher/export.inc"
#include "go-zetasql/legacy_zetasql/analyzer/input_argument_type_resolver_helper/export.inc"
#include "go-zetasql/legacy_zetasql/analyzer/lambda_util/export.inc"
#include "go-zetasql/legacy_zetasql/analyzer/name_scope/export.inc"
#include "go-zetasql/legacy_zetasql/analyzer/path_expression_span/export.inc"
#include "go-zetasql/legacy_zetasql/analyzer/set_operation_resolver_base/export.inc"
#include "go-zetasql/analyzer/rewriters/rewrite_subpipeline/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/check/export.inc"
#include "go-zetasql/base/general_trie/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/stl_util/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/base/varsetter/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/graph_element_utils/export.inc"
#include "go-zetasql/common/internal_analyzer_options/export.inc"
#include "go-zetasql/common/internal_analyzer_output_properties/export.inc"
#include "go-zetasql/common/status_payload_utils/export.inc"
#include "go-zetasql/common/thread_stack/export.inc"
#include "go-zetasql/common/warning_sink/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-zetasql/public/aggregation_threshold_utils/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output_properties/export.inc"
#include "go-zetasql/public/anon_function/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/civil_time/export.inc"
#include "go-zetasql/public/coercer/export.inc"
#include "go-zetasql/public/constant/export.inc"
#include "go-zetasql/public/cycle_detector/export.inc"
#include "go-zetasql/public/deprecation_warning_cc_proto/export.inc"
#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/interval_value/export.inc"
#include "go-zetasql/public/json_value/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/select_with_mode/export.inc"
#include "go-zetasql/public/signature_match_result/export.inc"
#include "go-zetasql/public/simple_catalog/export.inc"
#include "go-zetasql/public/sql_function/export.inc"
#include "go-zetasql/public/sql_tvf/export.inc"
#include "go-zetasql/public/sql_view/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/templated_sql_function/export.inc"
#include "go-zetasql/public/templated_sql_tvf_no_resolver/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/annotation/collation/export.inc"
#include "go-zetasql/public/functions/array_zip_mode_cc_proto/export.inc"
#include "go-zetasql/public/functions/convert_string/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/public/functions/normalize_mode_cc_proto/export.inc"
#include "go-zetasql/public/functions/range/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/column_factory/export.inc"
#include "go-zetasql/resolved_ast/comparator/export.inc"
#include "go-zetasql/resolved_ast/make_node_vector/export.inc"
#include "go-zetasql/resolved_ast/node_sources/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_builder/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_rewrite_visitor/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/target_syntax/export.inc"
#include "go-zetasql/scripting/parsed_script/export.inc"
#include "go-absl/algorithm/container/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/nullability/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/btree/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/container/node_hash_map/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/functional/any_invocable/export.inc"
#include "go-absl/log/log/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-googletest/googletest/export.inc"

#include "bridge.h"

#include "bridge_cc.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* googlesql_legacy_zetasql_analyzer_resolver_bind_cc */
