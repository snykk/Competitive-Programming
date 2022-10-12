package kata

import (
	"fmt"
	"strings"
)

func Accum(s string) string {
    var result string
    for index, char := range s {
      char := fmt.Sprintf("%c", char)
      result += strings.ToUpper(char)
      result += strings.Repeat(strings.ToLower(char), index)
      if index != len(s)-1 {
        result += "-"
      }
    }

    return result
}