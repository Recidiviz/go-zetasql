FROM golang:1.24-bullseye

RUN apt-get update && apt-get install -y --no-install-recommends curl ca-certificates gnupg
RUN curl https://bazel.build/bazel-release.pub.gpg | apt-key add -
RUN echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list
RUN apt-get update && apt-get install --no-install-recommends -y make g++ clang git python3 openjdk-11-jdk unzip
RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 100
RUN GOBIN=/usr/local/bin go install github.com/bazelbuild/bazelisk@latest

COPY googlesql /googlesql

WORKDIR /googlesql

ENV CC=clang
ENV CXX=clang++

RUN bazelisk build \
  --jobs=2 \
  --local_ram_resources=8192 \
  --local_cpu_resources=4 \
  --cxxopt=-std=c++20 \
  --host_cxxopt=-std=c++20 \
  '//googlesql/public:sql_formatter' \
  '//googlesql/public:anonymization_utils' \
  '//googlesql/resolved_ast:serialization_cc_proto' \
  '//googlesql/resolved_ast:resolved_ast_enums_cc_proto' \
  '//googlesql/resolved_ast:resolved_node_kind_cc_proto' \
  '//googlesql/resolved_ast:resolved_ast_cc_proto' \
  '//googlesql/scripting:variable_cc_proto' \
  '//googlesql/scripting:script_executor_state_cc_proto' \
  '//googlesql/scripting:script_exception_cc_proto' \
  '//googlesql/proto:options_cc_proto' \
  '//googlesql/proto:function_cc_proto' \
  '//googlesql/proto:simple_catalog_cc_proto' \
  '//googlesql/proto:internal_error_location_cc_proto' \
  '//googlesql/proto:anon_output_with_report_cc_proto' \
  '//googlesql/proto:placeholder_descriptor_cc_proto' \
  '//googlesql/parser:ast_enums_cc_proto' \
  '//googlesql/parser:parse_tree_cc_proto' \
  '//googlesql/public:parse_location_range_cc_proto' \
  '//googlesql/public:parse_resume_location_cc_proto' \
  '//googlesql/public:options_cc_proto' \
  '//googlesql/public:simple_value_cc_proto' \
  '//googlesql/public:function_cc_proto' \
  '//googlesql/public/proto:type_annotation_cc_proto' \
  '//googlesql/public:error_location_cc_proto' \
  '//googlesql/public:type_annotation_cc_proto' \
  '//googlesql/public:type_parameters_cc_proto' \
  '//googlesql/public:simple_constant_cc_proto' \
  '//googlesql/public:simple_table_cc_proto' \
  '//googlesql/public:builtin_function_cc_proto' \
  '//googlesql/public/functions:datetime_cc_proto' \
  '//googlesql/public/functions:normalize_mode_cc_proto' \
  '//googlesql/public/functions:rounding_mode_cc_proto' \
  '//googlesql/public:value_cc_proto' \
  '//googlesql/public:annotation_cc_proto' \
  '//googlesql/public:deprecation_warning_cc_proto' \
  '//googlesql/public:type_cc_proto' \
  '//googlesql/public:collation_cc_proto' \
  '//googlesql/public:formatter_options_cc_proto' \
  '//googlesql/public:type_modifiers_cc_proto' \
  '//googlesql/reference_impl:evaluation' \
  '//googlesql/scripting:procedure_extension_cc_proto'

COPY export.sh export.sh
