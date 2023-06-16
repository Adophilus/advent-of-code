const std = @import("std");
const builtin = @import("builtin");

pub fn main() !void {
    const file = try std.fs.cwd().openFile("input.txt", .{ .mode = .read_only });
    defer file.close();

    const reader = file.reader();
    var buffer: [100]u8 = undefined;
    var delim: u8 = '\n';
    if (builtin.os.tag == .windows)
        delim = '\r';

    var my_total_score: u32 = 0;
    var opponent_total_score: u32 = 0;

    while (try reader.readUntilDelimiterOrEof(&buffer, delim)) |line| {
        if (std.mem.eql(u8, line, "")) {
            break;
        }

        var it = std.mem.split(u8, line, " ");
        var plays: [2]u8 = undefined;

        var i: u8 = 0;
        while (it.next()) |play| {
            if (i > 1) {
                std.debug.print("Invalid data format! \"{s}\"\n", .{line});
                return;
            }
            plays[i] = play[0];
            i += 1;
        }

        var opponent_play = plays[0..1];
        var my_play: []u8 = plays[1..2];

        var opponent_score: u32 = 0;
        var my_score: u32 = 0;

        if (std.mem.eql(u8, my_play, "X")) {
            opponent_score += 6;
            my_score += 0;

            if (std.mem.eql(u8, opponent_play, "A")) {
                opponent_score += 1;
                my_score += 3;
            } else if (std.mem.eql(u8, opponent_play, "B")) {
                opponent_score += 2;
                my_score += 1;
            } else if (std.mem.eql(u8, opponent_play, "C")) {
                opponent_score += 3;
                my_score += 2;
            }
        } else if (std.mem.eql(u8, my_play, "Y")) {
            opponent_score += 3;
            my_score += 3;

            if (std.mem.eql(u8, opponent_play, "A")) {
                opponent_score += 1;
                my_score += 1;
            } else if (std.mem.eql(u8, opponent_play, "B")) {
                opponent_score += 2;
                my_score += 2;
            } else if (std.mem.eql(u8, opponent_play, "C")) {
                opponent_score += 3;
                my_score += 3;
            }
        } else if (std.mem.eql(u8, my_play, "Z")) {
            opponent_score += 0;
            my_score += 6;

            if (std.mem.eql(u8, opponent_play, "A")) {
                opponent_score += 1;
                my_score += 2;
            } else if (std.mem.eql(u8, opponent_play, "B")) {
                opponent_score += 2;
                my_score += 3;
            } else if (std.mem.eql(u8, opponent_play, "C")) {
                opponent_score += 3;
                my_score += 1;
            }
        }

        my_total_score += my_score;
        opponent_total_score += opponent_score;
    }

    std.debug.print("Your total score, assuming you stick to the script, would be {}\n", .{my_total_score});
    std.debug.print("Your opponent's score, assuming everything goes as planned, would be {}\n", .{opponent_total_score});
}
