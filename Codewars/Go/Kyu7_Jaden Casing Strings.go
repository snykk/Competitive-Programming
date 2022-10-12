package kata

import (
  "fmt"
  "strings"
)

func ToJadenCase(str string) string {
  var result string
	strSlice := strings.Split(str, " ")

	for index, item := range strSlice {
		result += strings.ToUpper(fmt.Sprintf("%c", item[0])) + item[1:]

		if index != len(strSlice)-1 {
			result += " "
		}
	}

	return result
}