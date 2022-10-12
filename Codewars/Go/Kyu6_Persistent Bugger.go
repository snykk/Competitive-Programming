package kata

import (
	"strconv"
)

func Persistence(n int) int {
	var total, dummyNum int
	var dummyCounter int = 1
	str := strconv.Itoa(n)

	for len(str) != 1 {
		for _, char := range str {
			dummyNum, _ = strconv.Atoi(string(char))
			dummyCounter *= dummyNum
		}

		str = strconv.Itoa(dummyCounter)
		dummyCounter = 1
		total += 1
	}

	return total
}
