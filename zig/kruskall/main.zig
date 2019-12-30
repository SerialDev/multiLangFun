const std = @import("std");
const io = @import("std").io;

const assert = std.debug.assert;

const Edge = struct{
    src: i32,
    dest: i32,
    weight: i32,
};

const Graph = struct{
    v: i32,
    e: i32,

    edges: []Edge,
};

fn createEdge(e:i32) Edge {
    var edge: Edge = Edge{.src = e, .dest = 0, .weight = 0};
    return edge;
    
} 
test "kruskal" {
    const V  = 4;
    std.debug.warn("first one:\n", V);
}

pub fn main()  !void {
    const stdout = &std.io.getStdOut().outStream().stream;
    try stdout.print("Hello, {}!\n", .{"world"});

    const e1 = createEdge(5);
    // const e1 = Struct{};
    try stdout.print("Hello, {}!", .{@typeId( e1)});
}


