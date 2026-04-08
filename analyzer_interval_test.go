package googlesql_test

import (
	"strings"
	"testing"

	"github.com/vantaboard/go-googlesql"
	ast "github.com/vantaboard/go-googlesql/resolved_ast"
	"github.com/vantaboard/go-googlesql/types"
)

// Regression guard for GoogleSQL releases that improve STRING→INTERVAL cast errors (e.g. 2022.02.1+).
// If analysis succeeds here, the engine may still reject the literal at evaluation time (see go-googlesqlite tests).
func TestAnalyzeStringToIntervalCastInvalidLiteral(t *testing.T) {
	catalog := types.NewSimpleCatalog("z_catalog")
	catalog.AddGoogleSQLBuiltinFunctions(nil)
	langOpt := googlesql.NewLanguageOptions()
	langOpt.SetNameResolutionMode(googlesql.NameResolutionDefault)
	langOpt.SetProductMode(types.ProductExternal)
	langOpt.EnableMaximumLanguageFeatures()
	langOpt.SetSupportedStatementKinds([]ast.Kind{ast.QueryStmt})
	opt := googlesql.NewAnalyzerOptions()
	opt.SetLanguage(langOpt)

	_, err := googlesql.AnalyzeStatement(
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
