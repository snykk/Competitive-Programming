package kata

import (
	"sort"
	"strings"
)

func FindShort(s string) int {
  strSlice := strings.Split(s, " ")

	sort.Slice(strSlice, func(i, j int) bool {
		return len(strSlice[i]) < len(strSlice[j])
	})

	return len(strSlice[0])
}