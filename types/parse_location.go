package types

import (
	"unsafe"

	zetasqlparser "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser"
	"github.com/goccy/go-zetasql/internal/helper"
)

type ParseLocationPoint struct {
	raw unsafe.Pointer
}

func (p *ParseLocationPoint) getRaw() unsafe.Pointer {
	return p.raw
}

func (p *ParseLocationPoint) Filename() string {
	var v unsafe.Pointer
	zetasqlparser.ParseLocationPoint_filename(p.raw, &v)
	return helper.PtrToString(v)
}

func (p *ParseLocationPoint) ByteOffset() int {
	var v int
	zetasqlparser.ParseLocationPoint_GetByteOffset(p.raw, &v)
	return v
}

func (p *ParseLocationPoint) String() string {
	var v unsafe.Pointer
	zetasqlparser.ParseLocationPoint_GetString(p.raw, &v)
	return helper.PtrToString(v)
}

type ParseLocationRange struct {
	raw unsafe.Pointer
}

func (r *ParseLocationRange) getRaw() unsafe.Pointer {
	return r.raw
}

func (r *ParseLocationRange) Start() *ParseLocationPoint {
	var v unsafe.Pointer
	zetasqlparser.ParseLocationRange_start(r.raw, &v)
	return newParseLocationPoint(v)
}

func (r *ParseLocationRange) End() *ParseLocationPoint {
	var v unsafe.Pointer
	zetasqlparser.ParseLocationRange_end(r.raw, &v)
	return newParseLocationPoint(v)
}

func (r *ParseLocationRange) String() string {
	var v unsafe.Pointer
	zetasqlparser.ParseLocationRange_GetString(r.raw, &v)
	return helper.PtrToString(v)
}

func newParseLocationPoint(v unsafe.Pointer) *ParseLocationPoint {
	if v == nil {
		return nil
	}
	return &ParseLocationPoint{raw: v}
}

func newParseLocationRange(v unsafe.Pointer) *ParseLocationRange {
	if v == nil {
		return nil
	}
	return &ParseLocationRange{raw: v}
}

func getRawParseLocationPoint(v *ParseLocationPoint) unsafe.Pointer {
	return v.raw
}

func getRawParseLocationRange(v *ParseLocationRange) unsafe.Pointer {
	return v.raw
}
