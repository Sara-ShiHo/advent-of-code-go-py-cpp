package main

import (
	"fmt"
	"os"
	"bufio"
)

func main() {
	var dat = Read("../../data/day03.txt")

	var result1 = findTrees(dat, 1, 1)
	var result2 = findTrees(dat, 3, 1)
	var result3 = findTrees(dat, 5, 1)
	var result4 = findTrees(dat, 7, 1)
	var result5 = findTrees(dat, 1, 2)
	fmt.Println(result1 * result2 * result3 * result4 * result5)
}

func Read(filename string) (lines []string) {
	file, _ := os.Open(filename)

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	return
}

func findTrees(dat []string, right int, down int) (n_X int){
    var length = len(dat[0])
    var right_pos = right
    var down_pos = down

	n_X = 0
	for down_pos < len(dat){
		var line = dat[down_pos]
		if string(line[right_pos]) == "#" {
			n_X += 1
		}
		right_pos = (right_pos + right) % length
		down_pos += down
	}
	return n_X
}

