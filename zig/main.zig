const std = @import("std");

// Implemented in zig/analyzer_smoke.cc, linked against the vendored
// ZetaSQL static libraries built by build.zig.
extern fn GoZetaSQL_AnalyzeStatement(sql: [*:0]const u8, out: [*]u8, out_capacity: c_int) c_int;

pub fn main() !void {
    var args = std.process.args();
    _ = args.next(); // program name
    const sql: [:0]const u8 = args.next() orelse "SELECT 1 + 2 AS three";

    var buf: [1 << 16]u8 = undefined;
    const rc = GoZetaSQL_AnalyzeStatement(sql.ptr, &buf, buf.len);
    const text = std.mem.sliceTo(&buf, 0);

    const stdout = std.io.getStdOut().writer();
    if (rc == 0) {
        try stdout.print("analyzed OK:\n{s}\n", .{text});
    } else {
        try stdout.print("analyze failed: {s}\n", .{text});
        std.process.exit(1);
    }
}
