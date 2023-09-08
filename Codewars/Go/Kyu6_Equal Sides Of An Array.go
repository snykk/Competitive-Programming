package kata


func getArraySum(arr []int) (sum int) {
	for _, num := range arr {
		sum += num
	}
	return sum
}

func FindEvenIndex(arr []int) int {
	for index := range arr {
		// fmt.Println("index: ", index)
		// fmt.Println("Left: ", arr[:index])
		// fmt.Println("Right: ", arr[index+1:])
		if getArraySum(arr[:index]) == getArraySum(arr[index+1:]) {
			return index
		}
	}
	return -1
}
