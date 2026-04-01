FROM golang:1.24-bullseye

RUN apt-get update && apt-get install -y --no-install-recommends curl ca-certificates gnupg
RUN curl https://bazel.build/bazel-release.pub.gpg | apt-key add -
RUN echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list
RUN apt-get update && apt-get install --no-install-recommends -y make g++ git python3 openjdk-11-jdk unzip
RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 100
RUN GOBIN=/usr/local/bin go install github.com/bazelbuild/bazelisk@latest

COPY zetasql /zetasql

WORKDIR /zetasql

RUN bazelisk build \
  --jobs=2 \
  --local_ram_resources=8192 \
  --local_cpu_resources=4 \
  '//zetasql/public:sql_formatter' \
  '//zetasql/resolved_ast:serialization_cc_proto' \
  '//zetasql/resolved_ast:resolved_ast_enums_cc_proto' \
  '//zetasql/resolved_ast:resolved_node_kind_cc_proto' \
  '//zetasql/resolved_ast:resolved_ast_cc_proto' \
  '//zetasql/scripting:variable_cc_proto' \
  '//zetasql/scripting:script_executor_state_cc_proto' \
  '//zetasql/scripting:script_exception_cc_proto' \
  '//zetasql/proto:options_cc_proto' \
  '//zetasql/proto:function_cc_proto' \
  '//zetasql/proto:simple_catalog_cc_proto' \
  '//zetasql/proto:internal_error_location_cc_proto' \
  '//zetasql/proto:anon_output_with_report_cc_proto' \
  '//zetasql/parser:ast_enums_cc_proto' \
  '//zetasql/parser:parse_tree_cc_proto' \
  '//zetasql/public:parse_location_range_cc_proto' \
  '//zetasql/public:parse_resume_location_cc_proto' \
  '//zetasql/public:options_cc_proto' \
  '//zetasql/public:simple_value_cc_proto' \
  '//zetasql/public:function_cc_proto' \
  '//zetasql/public/proto:type_annotation_cc_proto' \
  '//zetasql/public:error_location_cc_proto' \
  '//zetasql/public:type_annotation_cc_proto' \
  '//zetasql/public:type_parameters_cc_proto' \
  '//zetasql/public:simple_constant_cc_proto' \
  '//zetasql/public:simple_table_cc_proto' \
  '//zetasql/public:builtin_function_cc_proto' \
  '//zetasql/public/functions:datetime_cc_proto' \
  '//zetasql/public/functions:normalize_mode_cc_proto' \
  '//zetasql/public/functions:rounding_mode_cc_proto' \
  '//zetasql/public:value_cc_proto' \
  '//zetasql/public:annotation_cc_proto' \
  '//zetasql/public:deprecation_warning_cc_proto' \
  '//zetasql/public:type_cc_proto' \
  '//zetasql/public:collation_cc_proto' \
  '//zetasql/public:formatter_options_cc_proto' \
  '//zetasql/public:type_modifiers_cc_proto' \
  '//zetasql/scripting:procedure_extension_cc_proto'

COPY export.sh export.sh
