package kata

import (
	"strings"
)

func DuplicateEncode(word string) string {
	word = strings.ToLower(word)
	var res string

	for _, char := range word {
		if strings.Count(word, string(char)) > 1 {
			res += ")"
			continue
		}
		res += "("
	}

	return res
}