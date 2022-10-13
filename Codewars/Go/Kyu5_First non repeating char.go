package kata

// Write a function named first_non_repeating_letter that takes a string input, and returns the first character that is not repeated anywhere in the string.

// For example, if given the input 'stress', the function should return 't', since the letter t only occurs once in the string, and occurs first in the string.

// As an added challenge, upper- and lowercase letters are considered the same character, but the function should return the correct case for the initial letter. For example, the input 'sTreSS' should return 'T'.

// If a string contains all repeating characters, it should return an empty string ("") or None -- see sample tests.

import (
	"strings"
)

func FirstNonRepeating(str string) string {
	var result string

	for _, char := range str {
		dataList := strings.Split(strings.ToLower(str), strings.ToLower(string(char)))

		if len(dataList) == 2 {
			result = string(char)
			break
		}
	}

	return result
}