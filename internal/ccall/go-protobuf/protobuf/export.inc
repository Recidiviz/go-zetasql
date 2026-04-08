#ifndef PROTOBUF_EXPORT_H
#define PROTOBUF_EXPORT_H

#define InsertIfNotPresent protobuf_InsertIfNotPresent
#define GO_ZETASQL_PB_EXPORT(sym) export_protobuf_##sym

// Single port_def / port_undef for this translation unit (see port_def.inc).
#include "google/protobuf/port_def.inc"
#define GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF
#define GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF

// Headers like bytestream.h use GOOGLE_DISALLOW_EVIL_CONSTRUCTORS before
// logging.cc would pull in stubs/macros.h; define it once for the TU.
#include "google/protobuf/stubs/macros.h"

#include "google/protobuf/port.cc"

// protobuf lite sources
#include "google/protobuf/stubs/bytestream.cc"
#include "google/protobuf/stubs/bytestream.h"
#include "google/protobuf/stubs/common.cc"
#include "google/protobuf/stubs/hash.h"
#include "google/protobuf/stubs/int128.cc"
#include "google/protobuf/stubs/int128.h"
#include "google/protobuf/stubs/map_util.h"
#include "google/protobuf/stubs/mathutil.h"
#include "google/protobuf/stubs/status.cc"
#include "google/protobuf/stubs/status.h"
#include "google/protobuf/stubs/status_macros.h"
#include "google/protobuf/stubs/statusor.cc"
#include "google/protobuf/stubs/statusor.h"
#include "google/protobuf/stubs/stringpiece.cc"
#include "google/protobuf/stubs/stringpiece.h"
#include "google/protobuf/stubs/stringprintf.cc"
#include "google/protobuf/stubs/stringprintf.h"
#include "google/protobuf/stubs/logging.cc"

#include "google/protobuf/stubs/common.h"
#include "google/protobuf/stubs/structurally_valid.cc"

#include "google/protobuf/stubs/strutil.cc"
#include "google/protobuf/stubs/strutil.h"
#include "google/protobuf/stubs/time.cc"
#include "google/protobuf/stubs/time.h"
#include "google/protobuf/arena.cc"
#include "google/protobuf/arena_config.cc"
#include "google/protobuf/arenastring.cc"
#include "google/protobuf/inlined_string_field.cc"

#define Cardinality GO_ZETASQL_PB_EXPORT(Cardinality)
#define cpp_type GO_ZETASQL_PB_EXPORT(cpp_type)
#define real_type GO_ZETASQL_PB_EXPORT(real_type)
#include "google/protobuf/extension_set.cc"
#undef Cardinality
#undef cpp_type
#undef real_type

#include "google/protobuf/generated_message_bases.cc"
#include "google/protobuf/generated_message_util.cc"
#include "google/protobuf/generated_message_table_driven_lite.h"

#define MutableUnknownFields GO_ZETASQL_PB_EXPORT(MutableUnknownFields)
#include "google/protobuf/generated_message_table_driven_lite.cc"
#undef MutableUnknownFields

#include "google/protobuf/implicit_weak_message.cc"
#include "google/protobuf/message_lite.cc"
#include "google/protobuf/parse_context.cc"
#include "google/protobuf/repeated_field.cc"
#include "google/protobuf/repeated_ptr_field.cc"
// utf8_range::... definitions: link package utf8_range_link (blank-imported from bind_*.go).
#include "google/protobuf/wire_format_lite.cc"
#include "google/protobuf/io/coded_stream.cc"
#include "google/protobuf/io/zero_copy_stream.cc"
#include "google/protobuf/io/zero_copy_stream_impl_lite.cc"

// protobuf sources

#define schemas GO_ZETASQL_PB_EXPORT(any_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(any_file_default_instances)
#include "google/protobuf/any.pb.cc"
#undef file_default_instances
#undef schemas
#define schemas GO_ZETASQL_PB_EXPORT(api_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(api_file_default_instances)
#include "google/protobuf/api.pb.cc"
#undef file_default_instances
#undef schemas

#include "google/protobuf/any.cc"
#include "google/protobuf/any_lite.cc"
#include "google/protobuf/descriptor.cc"
#include "google/protobuf/descriptor_database.cc"
#define schemas GO_ZETASQL_PB_EXPORT(descriptor_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(descriptor_file_default_instances)
#include "google/protobuf/descriptor.pb.cc"
#undef file_default_instances
#undef schemas
#define schemas GO_ZETASQL_PB_EXPORT(duration_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(duration_file_default_instances)
#include "google/protobuf/duration.pb.cc"
#undef file_default_instances
#undef schemas
#include "google/protobuf/dynamic_message.cc"
#define schemas GO_ZETASQL_PB_EXPORT(empty_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(empty_file_default_instances)
#include "google/protobuf/empty.pb.cc"
#undef file_default_instances
#undef schemas


#include "google/protobuf/extension_set_heavy.cc"
#define schemas GO_ZETASQL_PB_EXPORT(field_mask_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(field_mask_file_default_instances)
#include "google/protobuf/field_mask.pb.cc"
#undef file_default_instances
#undef schemas

#include "google/protobuf/generated_message_tctable_gen.cc"
#define IsMapFieldInApi GO_ZETASQL_PB_EXPORT(IsMapFieldInApi)
#include "google/protobuf/generated_message_reflection.cc"
#undef IsMapFieldInApi
#include "google/protobuf/generated_message_table_driven_lite.h"
#include "google/protobuf/generated_message_table_driven.cc"
#include "google/protobuf/generated_message_tctable_lite.cc"
#include "google/protobuf/generated_message_tctable_full.cc"
#include "google/protobuf/map.cc"
#include "google/protobuf/map_field.cc"
#include "google/protobuf/message.cc"
#include "google/protobuf/reflection_mode.cc"
#include "google/protobuf/reflection_internal.h"
#include "google/protobuf/reflection_ops.cc"
#include "google/protobuf/service.cc"
#define schemas GO_ZETASQL_PB_EXPORT(source_context_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(source_context_file_default_instances)
#include "google/protobuf/source_context.pb.cc"
#undef file_default_instances
#undef schemas
#define schemas GO_ZETASQL_PB_EXPORT(struct_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(struct_file_default_instances)
#include "google/protobuf/struct.pb.cc"
#undef file_default_instances
#undef schemas

#include "google/protobuf/stubs/substitute.cc"
#include "google/protobuf/stubs/substitute.h"
#include "google/protobuf/text_format.cc"
#define schemas GO_ZETASQL_PB_EXPORT(timestamp_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(timestamp_file_default_instances)
#include "google/protobuf/timestamp.pb.cc"
#undef file_default_instances
#undef schemas
#define schemas GO_ZETASQL_PB_EXPORT(type_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(type_file_default_instances)
#include "google/protobuf/type.pb.cc"
#undef file_default_instances
#undef schemas
#include "google/protobuf/unknown_field_set.cc"
#include "google/protobuf/wire_format.cc"
#define schemas GO_ZETASQL_PB_EXPORT(wrappers_schemas)
#define file_default_instances GO_ZETASQL_PB_EXPORT(wrappers_file_default_instances)
#include "google/protobuf/wrappers.pb.cc"
#undef file_default_instances
#undef schemas

#include "google/protobuf/io/gzip_stream.cc"
#include "google/protobuf/io/zero_copy_sink.cc"
#include "google/protobuf/io/printer.cc"
#include "google/protobuf/io/strtod.cc"
#include "google/protobuf/io/tokenizer.cc"
#include "google/protobuf/io/zero_copy_stream_impl.cc"
#include "google/protobuf/compiler/importer.cc"
#include "google/protobuf/compiler/parser.cc"
#include "google/protobuf/util/message_differencer.cc"
#include "google/protobuf/util/field_comparator.cc"

#undef GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF
#include "google/protobuf/port_undef.inc"
/* Later zetasql *.pb.cc in the same TU include port_def.inc again; allow it. */
#undef GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF

#undef InsertIfNotPresent

// Same TU as protobuf call sites so LogMessage::operator<< template mangling matches.
#include "absl/log/internal/log_message.cc"

#endif
