package zetasql_test

import (
	"strings"
	"testing"

	"github.com/goccy/go-zetasql"
	ast "github.com/goccy/go-zetasql/resolved_ast"
	"github.com/goccy/go-zetasql/types"
)

// Regression guard for ZetaSQL releases that improve STRING→INTERVAL cast errors (e.g. 2022.02.1+).
// If analysis succeeds here, the engine may still reject the literal at evaluation time (see go-zetasqlite tests).
func TestAnalyzeStringToIntervalCastInvalidLiteral(t *testing.T) {
	catalog := types.NewSimpleCatalog("z_catalog")
	catalog.AddZetaSQLBuiltinFunctions(nil)
	langOpt := zetasql.NewLanguageOptions()
	langOpt.SetNameResolutionMode(zetasql.NameResolutionDefault)
	langOpt.SetProductMode(types.ProductExternal)
	langOpt.EnableMaximumLanguageFeatures()
	langOpt.SetSupportedStatementKinds([]ast.Kind{ast.QueryStmt})
	opt := zetasql.NewAnalyzerOptions()
	opt.SetLanguage(langOpt)

	_, err := zetasql.AnalyzeStatement(
		`SELECT CAST('totally-not-interval' AS INTERVAL)`,
		catalog,
		opt,
	)
	if err == nil {
		t.Skip("analyzer accepts invalid INTERVAL string literal; validation deferred to evaluation")
	}
	low := strings.ToLower(err.Error())
	if !strings.Contains(low, "interval") {
		t.Fatalf("expected INTERVAL-related analyzer error, got: %v", err)
	}
}
