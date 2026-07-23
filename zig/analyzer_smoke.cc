// C shim exposing a minimal ZetaSQL analyzer entry point to Zig.
//
// Zig cannot call C++ symbols directly, so this translation unit wraps
// zetasql::AnalyzeStatement() behind a C ABI. It is compiled as part of
// `zig build` together with the vendored ZetaSQL sources under
// internal/ccall.

#include <cstring>
#include <memory>
#include <string>

#include "absl/status/status.h"
#include "zetasql/public/analyzer.h"
#include "zetasql/public/analyzer_output.h"
#include "zetasql/public/language_options.h"
#include "zetasql/public/simple_catalog.h"
#include "zetasql/public/types/type_factory.h"
#include "zetasql/resolved_ast/resolved_ast.h"

extern "C" {

// Analyzes `sql` with a fresh catalog preloaded with the ZetaSQL builtin
// functions. Writes a NUL-terminated result into `out` (the resolved AST
// debug string on success, the error message on failure).
//
// Returns 0 on success, 1 on analysis error.
int GoZetaSQL_AnalyzeStatement(const char* sql, char* out, int out_capacity) {
  zetasql::TypeFactory type_factory;

  zetasql::AnalyzerOptions options;
  options.mutable_language()->SetSupportsAllStatementKinds();
  options.mutable_language()->EnableMaximumLanguageFeatures();

  zetasql::SimpleCatalog catalog("root", &type_factory);
  catalog.AddZetaSQLFunctions();

  std::unique_ptr<const zetasql::AnalyzerOutput> output;
  const absl::Status status =
      zetasql::AnalyzeStatement(sql, options, &catalog, &type_factory, &output);

  const std::string result =
      status.ok() ? output->resolved_statement()->DebugString()
                  : std::string(status.message());

  if (out != nullptr && out_capacity > 0) {
    const size_t n =
        std::min(result.size(), static_cast<size_t>(out_capacity - 1));
    std::memcpy(out, result.data(), n);
    out[n] = '\0';
  }
  return status.ok() ? 0 : 1;
}

}  // extern "C"
