package kata

// An integer partition of n is a weakly decreasing list of positive integers which sum to n.

// For example, there are 7 integer partitions of 5:

// [5], [4,1], [3,2], [3,1,1], [2,2,1], [2,1,1,1], [1,1,1,1,1].
// Write a function which returns the number of integer partitions of n. The function should be able to 
// find the number of integer partitions of n for n at least as large as 100.

func Partitions(n int) int {
	// ARE YOUE KNO WHAT... LOOK FOR THE PATTERN IS GOLD TO REDUCE COMPLEXITY
	var result = [][]int{}
	var dummy = []int{}
	var end int

	for i := 0; i < n; i++ {
		dummy = append(dummy, 1)
	}

	result = append(result, dummy)

	for i := 1; i < n+1; i++ {
		dummy = []int{}
		dummy = append(dummy, 0)
		for j := 1; j < i+1; j++ {
			if j > i-j {
				end = result[len(result)-j][i-j]
			} else {
				end = result[len(result)-j][j]
			}
			dummy = append(dummy, dummy[j-1]+end)
		}

		result = append(result, dummy)
	}

	return result[n][n]
}
