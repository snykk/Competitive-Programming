package kata

// Write a program that will calculate the number of trailing zeros in a factorial of a given number.

// N! = 1 * 2 * 3 *  ... * N

// Be careful 1000! has 2568 digits...

// For more info, see: http://mathworld.wolfram.com/Factorial.html

// Examples
// zeros(6) = 1
// # 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero

// zeros(12) = 2
// # 12! = 479001600 --> 2 trailing zeros
// Hint: You're not meant to calculate the factorial. Find another way to find the number of zeros.


// solution: 
// trailing zero is produced by 10. Since 10 is the product of 2 and 5, we need to count 
// the number of pairs of 2 and 5 factors in the factorial. Since there are typically more factors of 
// 2 than factors of 5, we only need to count the number of factors of 5.

func Zeros(n int) int {
	trailingZeros := 0

	// Keep dividing n by 5 and counting the result until n becomes less than 5
	for n >= 5 {
		n = n / 5
		trailingZeros += n
	}

	return trailingZeros
}


