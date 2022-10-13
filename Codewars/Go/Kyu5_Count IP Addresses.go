package kata

// Implement a function that receives two IPv4 addresses, and returns the number of addresses between them (including the first one, excluding the last one).

// All inputs will be valid IPv4 addresses in the form of strings. The last address will always be greater than the first one.

// * With input "10.0.0.0", "10.0.0.50"  => return   50
// * With input "10.0.0.0", "10.0.1.0"   => return  256
// * With input "20.0.0.10", "20.0.1.0"  => return  246

import (
	"math"
	"strconv"
	"strings"
)

func IpsBetween(start, end string) int {
	var num1, num2, total int
	ipStartList := strings.Split(start, ".")
	ipEndList := strings.Split(end, ".")
	var diffList = make([]int, 4)

	for i := 0; i < 4; i++ {
		num1, _ = strconv.Atoi(ipStartList[i])
		num2, _ = strconv.Atoi(ipEndList[i])
		diffList[i] = num2 - num1
	}

	// concept => diffList [w.x.y.z] = w*256^3 + x*256^2 + y*256^1 + z*256^0
	var beginMult = int(math.Pow(256, 3))
	for i := 0; i < 4; i++ {
		total += diffList[i] * beginMult
		beginMult /= 256
	}

	return total
}