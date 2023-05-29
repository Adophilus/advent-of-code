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
	mostCalories := 0

	calories := make([]int, 0)

	for _, line := range lines {
		if line == "" {
			sum := 0
			for _, calorie := range calories {
				sum += calorie
			}
			if sum > mostCalories {
				mostCalories = sum
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

	fmt.Printf("The elf carrying the most calories carries %d calories\n", mostCalories)

}
