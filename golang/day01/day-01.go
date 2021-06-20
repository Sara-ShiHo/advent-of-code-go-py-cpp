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
	var lines = Read("../../data/day01.txt")
	var nums1 = SelfIntersection(2020, lines)
	fmt.Println("Part I:")
	fmt.Println(nums1)
	fmt.Println(nums1[0] + nums1[1])
	fmt.Println(nums1[0] * nums1[1])
	fmt.Println()

	for _, element := range lines {
		var nums2 = SelfIntersection(2020 - element, lines)
		if len(nums2) == 2 {
			nums2 = append(nums2, element)
			fmt.Println("Part II:")
			fmt.Println(nums2)
			fmt.Println(nums2[0] + nums2[1] + nums2[2])
			fmt.Println(nums2[0] * nums2[1] * nums2[2])
			break
		}
	}
}

func Read(filename string) (lines []int) {
	file, _ := os.Open(filename)

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		i, _ := strconv.Atoi(scanner.Text())
		lines = append(lines, i)
	}
	return
}

func SelfIntersection(target int, a []int) (c []int) {
	m := make(map[int]bool)
	for _, item := range a {
		m[item] = true
	}
	for _, item := range a {
		if _, ok := m[target - item]; ok {
			c = append(c, item)
			if len(c) == 2 {
				break
			}
		}
	}
	return
}
