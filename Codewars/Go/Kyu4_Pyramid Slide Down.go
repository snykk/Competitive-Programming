package kata

// Lyrics...
// Pyramids are amazing! Both in architectural and mathematical sense. If you have a computer, you can mess with 
// pyramids even if you are not in Egypt at the time. For example, let's consider the following problem. Imagine
//  that you have a pyramid built of numbers, like this one here:

//    /3/
//   \7\ 4 
//  2 \4\ 6 
// 8 5 \9\ 3

// Here comes the task...
// Let's say that the 'slide down' is the maximum sum of consecutive numbers from the top to the bottom of the 
// pyramid. As you can see, the longest 'slide down' is 3 + 7 + 4 + 9 = 23

// Your task is to write a function that takes a pyramid representation as argument and returns its' largest 
// 'slide down'. For example:

// * With the input `[[3], [7, 4], [2, 4, 6], [8, 5, 9, 3]]`
// * Your function should return `23`.

// By the way...
// My tests include some extraordinarily high pyramids so as you can guess, brute-force method is a bad idea 
// unless you have a few centuries to waste. You must come up with something more clever than that.


func getMaxVal(num1, num2 int) int {
	if num1 > num2 {
		return num1
	}

	return num2
}

func LongestSlideDown(pyramid [][]int) int {
	// your code here
	if len(pyramid) == 1 {
		return pyramid[0][0]
	}

	var endLayer = pyramid[len(pyramid)-1]
	var newLayer = []int{}
	var dummySlice = []int{}

	for i := 1; i < len(endLayer); i++ {
		newLayer = append(newLayer, getMaxVal(endLayer[i], endLayer[i-1]))
	}

	for i := 0; i < len(newLayer); i++ {
		dummySlice = append(dummySlice, newLayer[i]+pyramid[len(pyramid)-2][i])
	}

	pyramid[len(pyramid)-2] = dummySlice

	return LongestSlideDown(pyramid[:len(pyramid)-1])
}
