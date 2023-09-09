package kata

// Write a function that takes an array of numbers (integers for the tests) and a target number. It should find two different items in the array that, when added together, give the target value. The indices of these items should then be returned in a tuple / list (depending on your language) like so: (index1, index2).

// For the purposes of this kata, some tests may have multiple answers; any valid solutions will be accepted.

// The input will always be valid (numbers will be an array of length 2 or greater, and all of the items will be numbers; target will always be the sum of two different items from that array).

// Based on: http://oj.leetcode.com/problems/two-sum/

// TwoSum([]int{1, 2, 3}, 4) // returns [2]int{0, 2}
// // the go translation has an issue where random tests accept either [2]int{0, 2} or [2]int{2, 0}, but fixed tests and sample tests demand the resulting slice to be sorted!
// // untill it's fixed, please sort your result in go.

func TwoSum(numbers []int, target int) [2]int {
  for i, val := range numbers {
    for j := i+1 ; j < len(numbers); j++ {
      if (val + numbers[j] == target) {
        return [2]int{i,j}
      }
    }
  }
  
  return [2]int{-1, -1}
}