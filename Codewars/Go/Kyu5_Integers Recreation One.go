package kata

import (
	"math"
)

// my function to check whether num is square or not
func isSquare(num int) bool {
	rawSquareRoot := math.Pow(float64(num), 0.5)
	susSquareRoot := int(rawSquareRoot)

	if float64(susSquareRoot) < rawSquareRoot && rawSquareRoot < float64(susSquareRoot+1) {
		return false
	}

	return true
}

// my function to total squareDiv
func getTotalSquareDiv(num int) int {
	var result int

	for i := 1; i <= num; i++ {
		if num%i == 0 {
			result += i * i
		}
	}

	return result
}

func ListSquared(m, n int)  [][]int {
  var result = [][]int{}
	var total int

	for i := m; i <= n; i++ {
		total = getTotalSquareDiv(i)

		if isSquare(total) {
			result = append(result, []int{i, total})
		}
	}
  
  return result
}