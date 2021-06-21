package main

import (
	"fmt"
	"os"
	"strings"
	"encoding/csv"
	"strconv"
)

func main() {
	csvFile,_ := os.Open("../../data/day02.txt")
	reader := csv.NewReader(csvFile)

	reader.Comma = ' '
	csvData,_ := reader.ReadAll()

	var validCounts1 = 0
	var validCounts2 = 0
	for _, each := range csvData {
		var rang = strings.Split(each[0], "-")
		var lower,_ = strconv.Atoi(rang[0])
		var upper,_ = strconv.Atoi(rang[1])
		var letter = strings.Replace(each[1], ":", "", -1)
		var password = each[2]
		validCounts1 += parse1(lower, upper, letter, password)
		validCounts2 += parse2(lower, upper, letter, password)
	}
	fmt.Println(validCounts1, len(csvData) - validCounts1)
	fmt.Println(validCounts2, len(csvData) - validCounts2)
}

func parse1(lower int, upper int, letter string, password string)(returnCount int) {
	var count = 0
	for _, l := range password {
		if string(l) == letter{
			count += 1
		}
	}
	if count < lower {
		return 0
	} else if count > upper {
		return 0
	} else {
		return 1
	}
}

func parse2(lower int, upper int, letter string, password string)(returnCount int) {
	var count = 0
	if string(password[lower - 1]) == letter {
		count += 1
	}
	if string(password[upper - 1]) == letter {
		count += 1
	}
	if count == 1 {
		return 1
	} else {
		return 0
	}
}
