const std = @import("std");
const builtin = @import("builtin");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();

    defer {
        const leaks_occurred = gpa.deinit();
        std.debug.print("Any memory leaks? {}\n", .{leaks_occurred});
    }

    const file = try std.fs.cwd().openFile("input.txt", .{ .mode = .read_only });
    defer file.close();
    const reader = file.reader();
    var buffer: [100]u8 = undefined;
    var maxCalories = [_]u32{ 0, 0, 0 };
    var caloriesList = std.ArrayList(u32).init(allocator);
    var delim: u8 = '\n';
    if (builtin.os.tag == .windows)
        delim = '\r';

    while (try reader.readUntilDelimiterOrEof(&buffer, delim)) |line| {
        if (builtin.os.tag == .windows)
            _ = try reader.readByte();
        if (std.mem.eql(u8, line, "")) {
            var sum: u32 = 0;
            for (caloriesList.items) |calories| {
                sum += calories;
            }
            var minCalorieIndex: usize = 0;
            for (maxCalories) |maxCalorie, i| {
                if (maxCalorie < maxCalories[minCalorieIndex])
                    minCalorieIndex = i;
            }
            if (sum > maxCalories[minCalorieIndex])
                maxCalories[minCalorieIndex] = sum;
            caloriesList.clearAndFree();
        } else {
            const number = try std.fmt.parseInt(u32, line, 10);
            try caloriesList.append(number);
        }
    }

    std.debug.print("The elves with the most calories have {d}, {d}, and {d} calories\n", .{ maxCalories[0], maxCalories[1], maxCalories[2] });
}
