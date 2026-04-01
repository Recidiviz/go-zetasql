module github.com/goccy/go-zetasql/internal/cmd/generator

go 1.24

require (
	github.com/bazelbuild/buildtools v0.0.0-20220211113555-f1ead6bc540d
	github.com/goccy/go-yaml v1.9.5
	github.com/goccy/go-zetasql v0.0.0
)

replace github.com/goccy/go-zetasql => ../../..

require (
	github.com/fatih/color v1.10.0 // indirect
	github.com/mattn/go-colorable v0.1.12 // indirect
	github.com/mattn/go-isatty v0.0.14 // indirect
	golang.org/x/sys v0.15.0 // indirect
	golang.org/x/xerrors v0.0.0-20200804184101-5ec99f83aff1 // indirect
)
