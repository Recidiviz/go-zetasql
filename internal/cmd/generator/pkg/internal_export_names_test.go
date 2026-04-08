package pkg

import (
	"os"
	"path/filepath"
	"runtime"
	"strings"
	"testing"
)


func TestBuildReplaceNameEntriesOmitsDescriptorTablesExceptProtobuf(t *testing.T) {
	_, thisFile, _, _ := runtime.Caller(0)
	pkgDir := filepath.Dir(thisFile)
	repoCfg := filepath.Join(pkgDir, "..", "config.yaml")
	raw, err := os.ReadFile(repoCfg)
	if err != nil {
		t.Fatal(err)
	}
	cfg, err := LoadConfig(raw)
	if err != nil {
		t.Fatal(err)
	}
	g := &Generator{cfg: cfg}
	g.internalExportNames = []string{
		"google_2fprotobuf_2ftimestamp_2eproto",
		"descriptor_table_google_2fprotobuf_2ftimestamp_2eproto",
		"TableStruct_google_2fprotobuf_2ftimestamp_2eproto",
	}
	leaf := g.buildReplaceNameEntries("googlesql/parser/location")
	for _, e := range leaf {
		if strings.HasPrefix(e.Name, "descriptor_table_google_2fprotobuf") {
			t.Fatalf("leaf package should not get google well-known descriptor renames: %q", e.Name)
		}
	}
	proto := g.buildReplaceNameEntries(goProtobufCCLibPkgKey)
	var saw bool
	for _, e := range proto {
		if e.Name == "descriptor_table_google_2fprotobuf_2ftimestamp_2eproto" {
			saw = true
			break
		}
	}
	if !saw {
		t.Fatalf("protobuf/protobuf should include descriptor_table_google_2fprotobuf_2ftimestamp_2eproto")
	}
}
