package kata

import (
  "unicode"
)

func Rot13(msg string) string {
  var abj string = "abcdefghijklmnopqrstuvwxyz"
	var dummyPosition int
	var result string

	for _, charMsg := range msg {
		// iterate every message character
		if unicode.IsLetter(charMsg) {
			for index, charAbj := range abj {
				// iterate to find abjad index of letter
				if unicode.ToLower(charMsg) == charAbj {
					dummyPosition = index

					dummyPosition += 13 // shift position
					dummyPosition %= 26 // implement limit

					// assign new letter
					if unicode.IsUpper(charMsg) {
						result += string(unicode.ToUpper(rune(abj[dummyPosition])))
						continue
					}

					result += string(abj[dummyPosition])
					break
				}
			}

			continue
		}

		result += string(charMsg)
	}

	return result
}