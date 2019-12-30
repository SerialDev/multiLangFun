const std = @import("std");
const io = @import("std").io;

const assert = std.debug.assert;

const edge = struct{
    src: i32,
    dest: i32,
    weight: i32,
};

const graph = struct{
    v: i32,
    e: i32,

    edges: []edge,
};

test "kruskal" {
    const V  = 4;
    std.debug.warn("first one:\n", V);
}

pub fn main()  !void {
    const stdout = &std.io.getStdOut().outStream().stream;
    try stdout.print("Hello, {}!\n", .{"world"});
}
