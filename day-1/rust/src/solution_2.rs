use std::fs;

fn main() {
    let file_content = fs::read_to_string("input.txt").unwrap();
    let lines = file_content.lines();
    let mut max_calories = [0, 0, 0];
    let mut sum = 0;
    for line in lines {
        if line.is_empty() {
            let mut least_calorie_index = 0;
            for (index, max_calorie) in max_calories.iter().enumerate() {
                if max_calorie < &max_calories[least_calorie_index] {
                    least_calorie_index = index;
                }
            }
            if sum > max_calories[least_calorie_index] {
                max_calories[least_calorie_index] = sum;
            }
            sum = 0;
            continue;
        }
        let number: i32 = line.parse().unwrap();
        sum += number;
    }
    println!(
        "The elves carrying the most calories carry {}, {}, and {} calories",
        max_calories[0], max_calories[1], max_calories[2]
    );
    println!(
        "Their cumulative calories is {}",
        max_calories.iter().map(|c| c).sum::<i32>()
    );
}
