// find the two entries that sum to 2020
// and then multiply those two numbers together


package main

import (
	"fmt"
    "os"
	"bufio"
	"strconv"
)

func main() {
	var lines, lines_diff = Read("../data/day01.txt")
	var nums = Intersection(lines, lines_diff)
	fmt.Println(nums)
	fmt.Println(nums[0] * nums[1])
}

func Read(filename string) (lines []int, lines_diff []int) {
    file, _ := os.Open("../data/day01.txt")

    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
		i, _ := strconv.Atoi(scanner.Text())
        lines = append(lines, i)
		lines_diff = append(lines_diff, 2020 - i)
    }
	return
}

func Intersection(a, b []int) (c []int) {
	m := make(map[int]bool)
	for _, item := range a {
			m[item] = true
	}
	for _, item := range b {
			if _, ok := m[item]; ok {
					c = append(c, item)
			}
	}
	return
}