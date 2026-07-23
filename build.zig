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
    .{
        .name = "protobuf",
        .root = ccall ++ "/protobuf/google",
        .excludes = &.{ "test", "mock", "/compiler/" },
    },
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
