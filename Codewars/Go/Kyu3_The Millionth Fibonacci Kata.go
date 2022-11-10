package kata

// The year is 1214. One night, Pope Innocent III awakens to find the the archangel Gabriel floating before him. Gabriel thunders to the pope:

// Gather all of the learned men in Pisa, especially Leonardo Fibonacci. In order for the crusades in the holy lands to be successful, these men
// must calculate the millionth number in Fibonacci's recurrence. Fail to do this, and your armies will never reclaim the holy land. It is His will.

// The angel then vanishes in an explosion of white light.

// Pope Innocent III sits in his bed in awe. How much is a million? he thinks to himself. He never was very good at math.

// He tries writing the number down, but because everyone in Europe is still using Roman numerals at this moment in history, he cannot represent
// this number. If he only knew about the invention of zero, it might make this sort of thing easier.

// He decides to go back to bed. He consoles himself, The Lord would never challenge me thus; this must have been some deceit by the devil. A pretty 
// horrendous nightmare, to be sure.

// Pope Innocent III's armies would go on to conquer Constantinople (now Istanbul), but they would never reclaim the holy land as he desired.

// In this kata you will have to calculate fib(n) where:

// fib(0) := 0
// fib(1) := 1
// fin(n + 2) := fib(n + 1) + fib(n)
// Write an algorithm that can handle n up to 2000000.

// Your algorithm must output the exact integer answer, to full precision. Also, it must correctly handle negative numbers as input.

// HINT I: Can you rearrange the equation fib(n + 2) = fib(n + 1) + fib(n) to find fib(n) if you already know fib(n + 1) and fib(n + 2)? Use this to 
// reason what value fib has to have for negative values.

// HINT II: See https://web.archive.org/web/20220614001843/https://mitpress.mit.edu/sites/default/files/sicp/full-text/book/book-Z-H-11.html#%_sec_1.2.4


import (
  "math"
  "math/big"
) 

func fibHelper(num int64) (*big.Int, *big.Int) {
	// base 1
	if num == 0 {
		return big.NewInt(0), big.NewInt(1)
	}

	// base 2
	if num == 1 {
		return big.NewInt(1), big.NewInt(1)
	}

	// implement recursive
	n1, n2 := fibHelper(int64(math.Floor(float64(num) / 2)))

	// scenario => a = n1 * (2*n2 - n1)
	// scenario => b = n2*n2 + n1*n1
	// docs: math/big => https://pkg.go.dev/math/big
	a := big.NewInt(1).Mul(n1, big.NewInt(0).Sub(big.NewInt(1).Mul(n2, big.NewInt(2)), n1))
	b := big.NewInt(0).Add(big.NewInt(1).Mul(n2, n2), big.NewInt(1).Mul(n1, n1))

	if num%2 == 0 {
		return a, b
	}

	return b, big.NewInt(0).Add(a, b)
}

func fib(n int64) *big.Int {
	if n >= 0 {
		result, _ := fibHelper(n)
		return result
	}

	if n%2 == 0 {
		result, _ := fibHelper(n * -1)
		return big.NewInt(0).Sub(big.NewInt(0), result)
	}

	result, _ := fibHelper(n * -1)
	return result
}
