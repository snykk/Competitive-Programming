package kata

import "sort"

func InAscOrder(numbers []int) bool {
  return sort.IntsAreSorted(numbers)
}