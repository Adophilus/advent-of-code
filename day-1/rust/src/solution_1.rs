use std::fs;

fn main() {
    println!("Beginning of solution 1");
    let file_content = fs::read_to_string("input.txt").unwrap();
    let lines = file_content.split("\n");
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
        sum += line.parse::<i32>().unwrap();
    }
    println!(
        "The elf carrying the most calories carries {} calories",
        max
    );
}
