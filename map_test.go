package googlesql_test

import (
	"testing"

	"github.com/vantaboard/go-googlesql"
	"github.com/vantaboard/go-googlesql/resolved_ast"
	"github.com/vantaboard/go-googlesql/types"
)

func TestNodeMap(t *testing.T) {
	const tableName = "z_table"
	catalog := types.NewSimpleCatalog("z_catalog")
	catalog.AddTable(
		types.NewSimpleTable(tableName, []types.Column{
			types.NewSimpleColumn(tableName, "col1", types.Int64Type()),
			types.NewSimpleColumn(tableName, "col2", types.StringType()),
		}),
	)
	catalog.AddGoogleSQLBuiltinFunctions(nil)
	langOpt := googlesql.NewLanguageOptions()
	langOpt.SetNameResolutionMode(googlesql.NameResolutionDefault)
	langOpt.SetProductMode(types.ProductExternal)
	langOpt.SetSupportedStatementKinds([]resolved_ast.Kind{resolved_ast.QueryStmt})
	opt := googlesql.NewAnalyzerOptions()
	opt.SetAllowUndeclaredParameters(true)
	opt.SetLanguage(langOpt)
	opt.SetParseLocationRecordType(googlesql.ParseLocationRecordFullNodeScope)

	query := `SELECT SUM(col1), col2 FROM z_table GROUP BY col2 HAVING SUM(col1) > 100`

	analyzerOut, err := googlesql.AnalyzeStatement(query, catalog, opt)
	if err != nil {
		t.Fatal(err)
	}
	// ParserOptions live in the parser CGO shard; LanguageOptions from the root
	// shard cannot be passed across (distinct C++ namespaces). Default parser
	// options are sufficient for this parse.
	node, err := googlesql.ParseStatement(query, googlesql.NewParserOptions())
	if err != nil {
		t.Fatal(err)
	}

	resolvedNode := analyzerOut.Statement()
	nodeMap := googlesql.NewNodeMap(resolvedNode, node)

	_ = resolved_ast.Walk(resolvedNode, func(n resolved_ast.Node) error {
		found := nodeMap.FindNodeFromResolvedNode(n)
		if len(found) == 0 {
			t.Fatal("failed to find node")
		}
		return nil
	})
}
