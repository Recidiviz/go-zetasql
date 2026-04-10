package pkg

import (
	"reflect"
	"testing"
)

func TestRemoveImportPathDoesNotMutateOriginalSlice(t *testing.T) {
	orig := []string{"a", "github.com/vantaboard/go-googlesql/internal/ccall/go-protobuf/protobuf", "c"}
	backup := append([]string(nil), orig...)
	out := removeImportPath(orig, "github.com/vantaboard/go-googlesql/internal/ccall/go-protobuf/protobuf")
	if !reflect.DeepEqual(orig, backup) {
		t.Fatalf("removeImportPath mutated input: got %v want %v", orig, backup)
	}
	want := []string{"a", "c"}
	if !reflect.DeepEqual(out, want) {
		t.Fatalf("got %v want %v", out, want)
	}
}
