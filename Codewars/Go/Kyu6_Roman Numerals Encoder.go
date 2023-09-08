package kata

// [solution 1] smart solution and little effort
func Solution(number int) string {
	// convert the number to a roman numeral
	var result string = ""

	var intArr []int = []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	var strArr []string = []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	var lenArrInt int = len(intArr)

	for i := 0; i < lenArrInt; i++ {
		if intArr[i] <= number {
			result += strArr[i]
			number -= intArr[i]
			i--
		}
	}

	return result
}

// [solution 2] cheap memory and runtime but more extra effort
// func Solution(number int) string {
// 	// convert the number to a roman numeral
// 	var result string = ""

// 	for number != 0 {
// 		if number >= 1000 {
// 			result += "M"
// 			number -= 1000
// 		} else if number >= 500 && number < 900 {
// 			result += "D"
// 			number -= 500
// 		} else if number >= 100 && number < 400 {
// 			result += "C"
// 			number -= 100
// 		} else if number >= 50 && number < 90 {
// 			result += "L"
// 			number -= 50
// 		} else if number >= 10 && number < 40 {
// 			result += "X"
// 			number -= 10
// 		} else if number >= 5 && number < 9 {
// 			result += "V"
// 			number -= 5
// 		} else if number >= 1 && number < 4 {
// 			result += "I"
// 			number -= 1
// 		} else if number == 4 {
// 			result += "IV"
// 			number -= 4
// 		} else if number == 9 {
// 			result += "IX"
// 			number -= 9
// 		} else if (number >= 40 || number >= 90) && number < 100 {
// 			result += "X"
// 			if number >= 90 {
// 				result += "C"
// 				number -= 90
// 			} else {
// 				result += "L"
// 				number -= 40
// 			}
// 		} else if (number >= 400 || number >= 900) && number < 1000 {
// 			result += "C"
// 			if number >= 900 {
// 				result += "M"
// 				number -= 900
// 			} else {
// 				result += "D"
// 				number -= 400
// 			}
// 		}
// 	}

// 	return result
// }
