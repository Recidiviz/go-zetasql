const std = @import("std");

// Builds the vendored ZetaSQL C++ sources (internal/ccall) into static
// libraries and links them into a small Zig executable that calls the
// ZetaSQL analyzer through the C shim in zig/analyzer_smoke.cc.
//
//   zig build              -> zig-out/bin/zetasql-analyzer-demo
//   zig build run          -> analyzes "SELECT 1 + 2 AS three"
//   zig build run -- "SELECT CONCAT('a', 'b')"

const ccall = "internal/ccall";

const include_dirs = [_][]const u8{
    ccall,
    ccall ++ "/protobuf",
    ccall ++ "/gtest",
    ccall ++ "/icu",
    ccall ++ "/re2",
    ccall ++ "/json",
    ccall ++ "/googleapis",
    ccall ++ "/flex/src",
};

// Mirrors the CXXFLAGS the cgo build uses, minus per-warning toggles
// (-w) and with UBSan disabled: the vendored code has benign UB that
// zig's default Debug sanitizers would otherwise trap on.
const cxx_flags = [_][]const u8{
    "-std=c++17",
    "-w",
    "-g0",
    "-fno-sanitize=undefined",
    // The vendored sources predate compilers that stopped including
    // <cstdint> transitively; force it in.
    "-include",
    "cstdint",
    "-DHAVE_PTHREAD",
    "-DU_COMMON_IMPLEMENTATION",
    "-DU_STATIC_IMPLEMENTATION=1",
};

const LibSpec = struct {
    name: []const u8,
    root: []const u8,
    exts: []const []const u8 = &.{".cc"},
    // A source file is skipped when its path contains any of these.
    excludes: []const []const u8 = &.{},
};

const lib_specs = [_]LibSpec{
    .{
        .name = "zetasql",
        .root = ccall ++ "/zetasql",
        .excludes = &.{
            "_test",      "test_util",     "/testdata/",
            "/testing/",  "/compliance/",  "/local_service/",
            "/tools/",    "/jdk/",         "/scripting/",
            "/examples/", "benchmark",     "fuzz",
        },
    },
    .{
        .name = "absl",
        .root = ccall ++ "/absl",
        .excludes = &.{
            "_test",     "test_util", "_testing",  "benchmark",
            "/mock",     "mock_",     "gentables", "print_hash_of",
        },
    },
    // protobuf is handled separately: the vendored tree mixes files from
    // several protobuf versions, and only the curated list maintained in
    // go-protobuf/protobuf/export.inc compiles as a set.
    .{
        .name = "icu",
        .root = ccall ++ "/icu/common",
        .exts = &.{ ".cpp", ".c" },
    },
    .{
        .name = "re2",
        .root = ccall ++ "/re2",
        .excludes = &.{ "test", "benchmark", "fuzz", "/python/" },
    },
    .{
        .name = "support", // farmhash + googleapis proto types
        .root = ccall ++ "/farmhash",
    },
};

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "zetasql-analyzer-demo",
        .root_source_file = b.path("zig/main.zig"),
        .target = target,
        .optimize = optimize,
    });
    exe.linkLibCpp();
    addIncludes(b, exe);
    exe.addCSourceFiles(.{
        .files = &.{"zig/analyzer_smoke.cc"},
        .flags = &cxx_flags,
    });

    for (lib_specs) |spec| {
        const lib = b.addStaticLibrary(.{
            .name = spec.name,
            .target = target,
            .optimize = optimize,
        });
        lib.linkLibCpp();
        addIncludes(b, lib);

        var files = collectSources(b, spec) catch |err| {
            std.debug.panic("collecting sources under {s}: {s}", .{
                spec.root, @errorName(err),
            });
        };
        // googleapis sources live outside the "support" root; append them.
        if (std.mem.eql(u8, spec.name, "support")) {
            files.appendSlice(&.{
                ccall ++ "/googleapis/google/type/date.pb.cc",
                ccall ++ "/googleapis/google/type/latlng.pb.cc",
                ccall ++ "/googleapis/google/type/timeofday.pb.cc",
            }) catch @panic("OOM");
        }
        lib.addCSourceFiles(.{ .files = files.items, .flags = &cxx_flags });
        exe.linkLibrary(lib);
    }

    {
        const lib = b.addStaticLibrary(.{
            .name = "protobuf",
            .target = target,
            .optimize = optimize,
        });
        lib.linkLibCpp();
        addIncludes(b, lib);
        const files = protobufSources(b) catch |err| {
            std.debug.panic("parsing protobuf export.inc: {s}", .{@errorName(err)});
        };
        lib.addCSourceFiles(.{ .files = files, .flags = &cxx_flags });
        exe.linkLibrary(lib);
    }

    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| run_cmd.addArgs(args);
    const run_step = b.step("run", "Analyze a statement with the ZetaSQL analyzer");
    run_step.dependOn(&run_cmd.step);
}

fn addIncludes(b: *std.Build, compile: *std.Build.Step.Compile) void {
    for (include_dirs) |dir| compile.addIncludePath(b.path(dir));
}

// Reads the curated protobuf source list out of the same file the cgo
// build uses (go-protobuf/protobuf/export.inc), skipping the google/type
// protos, which live under googleapis and are part of the support lib.
fn protobufSources(b: *std.Build) ![]const []const u8 {
    var files = std.ArrayList([]const u8).init(b.allocator);

    const inc = try b.build_root.handle.readFileAlloc(
        b.allocator,
        ccall ++ "/go-protobuf/protobuf/export.inc",
        1 << 20,
    );

    var lines = std.mem.tokenizeScalar(u8, inc, '\n');
    while (lines.next()) |line| {
        const prefix = "#include \"google/";
        if (!std.mem.startsWith(u8, line, prefix)) continue;
        const start = std.mem.indexOfScalar(u8, line, '"').? + 1;
        const end = std.mem.lastIndexOfScalar(u8, line, '"').?;
        const rel = line[start..end];
        if (!std.mem.endsWith(u8, rel, ".cc")) continue;
        if (std.mem.startsWith(u8, rel, "google/type/")) continue;
        try files.append(b.pathJoin(&.{ ccall ++ "/protobuf", rel }));
    }
    return files.items;
}

fn collectSources(b: *std.Build, spec: LibSpec) !std.ArrayList([]const u8) {
    var files = std.ArrayList([]const u8).init(b.allocator);

    var dir = try b.build_root.handle.openDir(spec.root, .{ .iterate = true });
    defer dir.close();

    var walker = try dir.walk(b.allocator);
    defer walker.deinit();

    walk: while (try walker.next()) |entry| {
        if (entry.kind != .file) continue;
        for (spec.exts) |ext| {
            if (std.mem.endsWith(u8, entry.basename, ext)) break;
        } else continue :walk;

        const path = b.pathJoin(&.{ spec.root, entry.path });
        for (spec.excludes) |pattern| {
            if (std.mem.indexOf(u8, path, pattern) != null) continue :walk;
        }
        try files.append(path);
    }

    // Deterministic ordering keeps zig's cache hits stable across runs.
    std.mem.sort([]const u8, files.items, {}, struct {
        fn lessThan(_: void, a: []const u8, c: []const u8) bool {
            return std.mem.lessThan(u8, a, c);
        }
    }.lessThan);
    return files;
}
