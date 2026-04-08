
#ifndef googlesql_legacy_zetasql_reference_impl_evaluation_bind_cc
#define googlesql_legacy_zetasql_reference_impl_evaluation_bind_cc

// switch namespace
#define differential_privacy googlesql_legacy_zetasql_reference_impl_evaluation_differential_privacy
#define googlesql googlesql_legacy_zetasql_reference_impl_evaluation_googlesql
#define googlesql_base googlesql_legacy_zetasql_reference_impl_evaluation_googlesql_base
#define googlesql_bison_parser googlesql_legacy_zetasql_reference_impl_evaluation_googlesql_bison_parser
#define re2 googlesql_legacy_zetasql_reference_impl_evaluation_re2
#define AbslInternalSleepFor googlesql_legacy_zetasql_reference_impl_evaluation_AbslInternalSleepFor
#define AbslInternalReportFatalUsageError googlesql_legacy_zetasql_reference_impl_evaluation_AbslInternalReportFatalUsageError
#define AbslInternalMutexYield googlesql_legacy_zetasql_reference_impl_evaluation_AbslInternalMutexYield
#define AbslInternalPerThreadSemPost googlesql_legacy_zetasql_reference_impl_evaluation_AbslInternalPerThreadSemPost
#define AbslInternalPerThreadSemWait googlesql_legacy_zetasql_reference_impl_evaluation_AbslInternalPerThreadSemWait
#define AbslContainerInternalSampleEverything googlesql_legacy_zetasql_reference_impl_evaluation_AbslContainerInternalSampleEverything
#define AbslInternalSpinLockDelay googlesql_legacy_zetasql_reference_impl_evaluation_AbslInternalSpinLockDelay
#define AbslInternalSpinLockWake googlesql_legacy_zetasql_reference_impl_evaluation_AbslInternalSpinLockWake
#define AbslInternalAnnotateIgnoreReadsBegin googlesql_legacy_zetasql_reference_impl_evaluation_AbslInternalAnnotateIgnoreReadsBegin
#define AbslInternalAnnotateIgnoreReadsEnd googlesql_legacy_zetasql_reference_impl_evaluation_AbslInternalAnnotateIgnoreReadsEnd
#define AbslInternalGetFileMappingHint googlesql_legacy_zetasql_reference_impl_evaluation_AbslInternalGetFileMappingHint
#define GoogleSqlalloc googlesql_legacy_zetasql_reference_impl_evaluation_GoogleSqlalloc
#define GoogleSqlfree googlesql_legacy_zetasql_reference_impl_evaluation_GoogleSqlfree
#define GoogleSqlrealloc googlesql_legacy_zetasql_reference_impl_evaluation_GoogleSqlrealloc
#define FLAGS_nooutput_asc_explicitly googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nooutput_asc_explicitly
#define FLAGS_nogooglesql_use_customized_flex_istream googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nogooglesql_use_customized_flex_istream
#define FLAGS_output_asc_explicitly googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_output_asc_explicitly
#define FLAGS_googlesql_use_customized_flex_istream googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_googlesql_use_customized_flex_istream
#define FLAGS_googlesql_type_factory_nesting_depth_limit googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_googlesql_type_factory_nesting_depth_limit
#define FLAGS_googlesql_read_proto_field_optimized_path googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_googlesql_read_proto_field_optimized_path
#define FLAGS_googlesql_format_max_output_width googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_googlesql_format_max_output_width
#define FLAGS_googlesql_min_length_required_for_edit_distance googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_googlesql_min_length_required_for_edit_distance
#define FLAGS_googlesql_simple_iterator_call_time_now_rows_period googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_googlesql_simple_iterator_call_time_now_rows_period
#define FLAGS_nogooglesql_type_factory_nesting_depth_limit googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nogooglesql_type_factory_nesting_depth_limit
#define FLAGS_nogooglesql_read_proto_field_optimized_path googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nogooglesql_read_proto_field_optimized_path
#define FLAGS_nogooglesql_format_max_output_width googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nogooglesql_format_max_output_width
#define FLAGS_nogooglesql_min_length_required_for_edit_distance googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nogooglesql_min_length_required_for_edit_distance
#define FLAGS_nogooglesql_simple_iterator_call_time_now_rows_period googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nogooglesql_simple_iterator_call_time_now_rows_period
#define FLAGS_googlesql_enough_stack_bytes googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_googlesql_enough_stack_bytes
#define FLAGS_nogooglesql_enough_stack_bytes googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nogooglesql_enough_stack_bytes
#define FLAGS_googlesql_canonicalize_signed_zero_to_string googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_googlesql_canonicalize_signed_zero_to_string
#define FLAGS_nogooglesql_canonicalize_signed_zero_to_string googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nogooglesql_canonicalize_signed_zero_to_string
#define FLAGS_googlesql_default_error_message_stability googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_googlesql_default_error_message_stability
#define FLAGS_nogooglesql_default_error_message_stability googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nogooglesql_default_error_message_stability
#define FLAGS_googlesql_redact_error_messages_for_tests googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_googlesql_redact_error_messages_for_tests
#define FLAGS_nogooglesql_redact_error_messages_for_tests googlesql_legacy_zetasql_reference_impl_evaluation_FLAGS_nogooglesql_redact_error_messages_for_tests
#define GoogleSqlFlexTokenizerBase googlesql_legacy_zetasql_reference_impl_evaluation_GoogleSqlFlexTokenizerBase
#define GoogleSqlFlexLexer googlesql_legacy_zetasql_reference_impl_evaluation_GoogleSqlFlexLexer
#define UCaseMap googlesql_legacy_zetasql_reference_impl_evaluation_UCaseMap

#define GO_EXPORT(def) export_googlesql_legacy_zetasql_reference_impl_evaluation_ ## def
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
#include "googlesql/legacy_zetasql/reference_impl/evaluation.h"
#include "googlesql/legacy_zetasql/reference_impl/function.h"
#include "googlesql/legacy_zetasql/reference_impl/operator.h"
#include "googlesql/legacy_zetasql/reference_impl/tuple.h"
#include "googlesql/legacy_zetasql/reference_impl/tuple_comparator.h"
//#undef private

// include sources
#include "googlesql/legacy_zetasql/reference_impl/aggregate_op.cc"
#include "googlesql/legacy_zetasql/reference_impl/analytic_op.cc"
#include "googlesql/legacy_zetasql/reference_impl/evaluation.cc"
#include "googlesql/legacy_zetasql/reference_impl/function.cc"
#include "googlesql/legacy_zetasql/reference_impl/operator.cc"
#include "googlesql/legacy_zetasql/reference_impl/pattern_matching_op.cc"
#include "googlesql/legacy_zetasql/reference_impl/relational_op.cc"
#include "googlesql/legacy_zetasql/reference_impl/tuple.cc"
#include "googlesql/legacy_zetasql/reference_impl/tuple_comparator.cc"
#include "googlesql/legacy_zetasql/reference_impl/value_expr.cc"

// include dependencies
#include "go-zetasql/legacy_zetasql/reference_impl/common/export.inc"
#include "go-zetasql/legacy_zetasql/reference_impl/proto_util/export.inc"
#include "go-zetasql/legacy_zetasql/reference_impl/type_parameter_constraints/export.inc"
#include "go-zetasql/legacy_zetasql/reference_impl/variable_generator/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-google/type/date_cc_proto/export.inc"
#include "go-google/type/timeofday_cc_proto/export.inc"
#include "go-zetasql/common/string_util/export.inc"
#include "go-zetasql/common/thread_stack/export.inc"
#include "go-zetasql/public/functions/array_zip_mode_cc_proto/export.inc"
#include "go-zetasql/public/functions/differential_privacy_cc_proto/export.inc"
#include "go-zetasql/public/functions/rounding_mode_cc_proto/export.inc"
#include "go-zetasql/public/types/timestamp_util/export.inc"
#include "go-zetasql/public/anonymization_utils/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/initialize_required_fields/export.inc"
#include "go-zetasql/common/internal_value/export.inc"
#include "go-zetasql/proto/anon_output_with_report_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/civil_time/export.inc"
#include "go-zetasql/public/coercer/export.inc"
#include "go-zetasql/public/collator_lite/export.inc"
#include "go-zetasql/public/evaluator_table_iterator/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/interval_value/export.inc"
#include "go-zetasql/public/json_value/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/proto_value_conversion/export.inc"
#include "go-zetasql/public/sql_tvf/export.inc"
#include "go-zetasql/public/templated_sql_tvf/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/uuid_value/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/functions/arithmetics/export.inc"
#include "go-zetasql/public/functions/bitcast/export.inc"
#include "go-zetasql/public/functions/bitwise/export.inc"
#include "go-zetasql/public/functions/common_proto/export.inc"
#include "go-zetasql/public/functions/numeric/export.inc"
#include "go-zetasql/public/functions/comparison/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/public/functions/distance/export.inc"
#include "go-zetasql/public/functions/string_format/export.inc"
#include "go-zetasql/public/functions/generate_array/export.inc"
#include "go-zetasql/public/functions/json/export.inc"
#include "go-zetasql/public/functions/math/export.inc"
#include "go-zetasql/public/functions/net/export.inc"
#include "go-zetasql/public/functions/normalize_mode_cc_proto/export.inc"
#include "go-zetasql/public/functions/parse_date_time/export.inc"
#include "go-zetasql/public/functions/percentile/export.inc"
#include "go-zetasql/public/functions/regexp/export.inc"
#include "go-zetasql/public/functions/string/export.inc"
#include "go-zetasql/public/functions/like/export.inc"
#include "go-zetasql/public/functions/match_recognize/compiled_pattern/export.inc"
#include "go-zetasql/public/functions/match_recognize/match_partition/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/reference_impl/functions/like/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-googletest/googletest/export.inc"
#include "go-absl/algorithm/container/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/btree/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/container/node_hash_map/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/hash/hash/export.inc"
#include "go-zetasql/base/check/export.inc"
#include "go-absl/log/die_if_null/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/random/random/export.inc"
#include "go-absl/random/distributions/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-proto/confidence_interval_cc_proto/export.inc"
#include "go-proto/data_cc_proto/export.inc"
#include "go-algorithms/algorithm/export.inc"
#include "go-algorithms/bounded-sum/export.inc"
#include "go-algorithms/bounded-mean/export.inc"
#include "go-algorithms/bounded-standard-deviation/export.inc"
#include "go-algorithms/bounded-variance/export.inc"
#include "go-algorithms/quantiles/export.inc"
#include "go-zetasql/base/flat_set/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/optional_ref/export.inc"
#include "go-zetasql/base/stl_util/export.inc"
#include "go-zetasql/base/exactfloat/export.inc"
#include "go-re2/re2/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-google/rpc/status_cc_proto/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/clock/export.inc"

#include "bridge.h"

#include "bridge_cc.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* googlesql_legacy_zetasql_reference_impl_evaluation_bind_cc */
