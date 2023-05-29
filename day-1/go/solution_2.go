package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	data, err := os.ReadFile("input.txt")
	if err != nil {
		panic(err)
	}

	lines := strings.Split(string(data), "\r\n")
	mostCalories := make([]int, 3)

	calories := make([]int, 0)

	for _, line := range lines {
		if line == "" {
			sum := 0
			for _, calorie := range calories {
				sum += calorie
			}
			leastCalorieIndex := 0
			for index, mostCalorie := range mostCalories {
				if mostCalorie < mostCalories[leastCalorieIndex] {
					leastCalorieIndex = index
				}
			}
			if sum > mostCalories[leastCalorieIndex] {
				mostCalories[leastCalorieIndex] = sum
			}
			calories = make([]int, 0)
			continue
		}
		number, err := strconv.Atoi(line)
		if err != nil {
			panic(err)
		}
		calories = append(calories, number)
	}

	fmt.Printf("The elves carrying the most calories carry %d, %d and %d calories\n", mostCalories[0], mostCalories[1], mostCalories[2])
	fmt.Printf("Their combined calories is: %d\n", mostCalories[0]+mostCalories[1]+mostCalories[2])
}
