use std::fs;

fn main() {
    let file_content = fs::read_to_string("input.txt").unwrap();
    let lines = file_content.lines();
    let mut max = 0;
    let mut sum = 0;
    for line in lines {
        if line.is_empty() {
            if sum > max {
                max = sum;
            }
            sum = 0;
            continue;
        }
        let number: i32 = line.parse().unwrap();
        sum += number;
    }
    println!(
        "The elf carrying the most calories carries {} calories",
        max
    );
}
