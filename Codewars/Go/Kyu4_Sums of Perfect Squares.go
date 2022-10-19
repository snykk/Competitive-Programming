package kata

// The task is simply stated. Given an integer n (3 < n < 109), find the length of the smallest list of perfect 
// which add up to n. Come up with the best algorithm you can; you'll need it!

// Examples:

// sum_of_squares(17) = 2
// 17 = 16 + 1 (16 and 1 are perfect squares).
// sum_of_squares(15) = 4
// 15 = 9 + 4 + 1 + 1. There is no way to represent 15 as the sum of three perfect squares.
// sum_of_squares(16) = 1
// 16 itself is a perfect square.
// Time constraints:

// 5 easy (sample) test cases: n < 20

// 5 harder test cases: 1000 < n < 15000

// 5 maximally hard test cases: 5e8 < n < 1e9

// 1000 random maximally hard test cases: 1e8 < n < 1e9


import "math"

func isSquare(n uint64) bool {
	sq := uint64(math.Floor(math.Sqrt(float64(n))))
	return sq*sq == n
}

func SumOfSquares(n uint64) uint64 {
	if n == 0 {
		return 0
	}

	if isSquare(n) {
		return 1
	}

	// Four-square and three-square theorems.
	for n&3 == 0 { 
		n >>= 2 
	}
	if n&7 == 7 {
		return 4
	}

	// Check if the number can be decomposed into sum of two squares.
	for i := uint64(1); i*i <= n; i++ {
		if isSquare(n - i*i) {
			return 2
		}
	}

	// Bottom case of three-square theorem.
	return 3
}