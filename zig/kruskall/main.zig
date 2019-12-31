const std = @import("std");
const io = @import("std").io;

const assert = std.debug.assert;

const Edge = struct{
    src: i32,
    dest: i32,
    weight: i32,
};

const Graph = struct{
    vert: i32,
    edge: i32,

    edges: [1]Edge, // broken LLVM module found: Call parameter type does not match function signature! This is a bug in the Zig compiler.
};

fn createEdge(e:i32) Edge {
    var edge: Edge = Edge{.src = e, .dest = 0, .weight = 0};
    return edge;

}

fn createGraph(v:i32, e:i32) Graph {
    var edge = [_]Edge{createEdge(e)};
    var graph: Graph = Graph{.vert = v, .edge = e, .edges = edge };
    return graph;
}

test "kruskal" {
    const V  = 4;
    std.debug.warn("first one:\n", V);
}

pub fn main()  !void {
    const stdout = &std.io.getStdOut().outStream().stream;
    try stdout.print("Hello, {}!\n", .{"world"});

    const e1 = createEdge(5);
    const g1 = createGraph(4, 10);
    // const e1 = Struct{};
    // try stdout.print("Hello, {}!", .{@typeName(e1.src)});
}




