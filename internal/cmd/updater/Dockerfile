# Builds google/googlesql at a pinned tag and exports Bazel artifacts for the Go updater.
# Build: make -C internal/cmd/updater build   (or docker build -t googlesql-updater .)
# Bookworm (glibc 2.36): Bazel's hermetic LLVM toolchain requires GLIBC_2.32+ (bullseye is too old).
FROM golang:1.24-bookworm

RUN apt-get update && apt-get install -y --no-install-recommends curl ca-certificates gnupg git \
    && rm -rf /var/lib/apt/lists/*
RUN curl https://bazel.build/bazel-release.pub.gpg | apt-key add -
RUN echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list
RUN apt-get update && apt-get install --no-install-recommends -y make g++ clang git python3 openjdk-17-jdk-headless unzip \
    && rm -rf /var/lib/apt/lists/*
RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 100
RUN GOBIN=/usr/local/bin go install github.com/bazelbuild/bazelisk@latest

ARG GOOGLESQL_REF=2026.01.1
ENV GOOGLESQL_REF=${GOOGLESQL_REF}

RUN git clone --depth 1 --branch "${GOOGLESQL_REF}" https://github.com/google/googlesql.git /googlesql

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
  '//googlesql/proto:script_exception_cc_proto' \
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
  '//googlesql/scripting:procedure_extension_cc_proto' \
  '//googlesql/base/net:gen_public_suffix_data'

RUN mkdir -p /bazel-meta && \
  bazelisk info output_base > /bazel-meta/output_base.txt && \
  bazelisk info execution_root > /bazel-meta/execution_root.txt

COPY export.sh /export.sh
RUN chmod +x /export.sh

WORKDIR /
ENTRYPOINT ["/export.sh"]
CMD ["/tmp"]
