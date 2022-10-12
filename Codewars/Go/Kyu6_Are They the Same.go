package kata

import (
  "fmt"
  "sort"
)

func absoluteConvert(arr *[]int) {
  for index := 0; index < len(*arr); index++ {
    if (*arr)[index] < 0 {
      (*arr)[index] = (*arr)[index] * -1
    }
  }
}

func Comp(array1 []int, array2 []int) bool {
  if len(array1) == 0 || len(array2) == 0 {
    return false
  }

  absoluteConvert(&array1)
  absoluteConvert(&array2)

  sort.Ints(array1)
  sort.Ints(array2)

  for i := 0; i < len(array1); i++ {
    if array1[i]*array1[i] != array2[i] {
      return false
    }
  }

  return true
}
