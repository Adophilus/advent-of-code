const std = @import("std");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();

    defer {
        const leaks_occurred = gpa.deinit();
        if (leaks_occurred) @panic("Memory leak detected!");
    }

    const file = try std.fs.cwd().openFile("input.txt", .{ .mode = .read_only });
    defer file.close();
    const reader = file.reader();
    var buffer: [100]u8 = undefined;
    // var max = 0;
    var caloriesList = std.ArrayList(u32).init(allocator);

    while (try reader.readUntilDelimiterOrEof(&buffer, '\n')) |line| {
        if (std.mem.eql(u8, line, ""))
            std.debug.print("break\n", .{});
        const number = try std.fmt.parseInt(u32, line, 10);
        try caloriesList.append(number);
    }
}
