package kata

func MoveZeros(arr []int) []int {
    for i, j := 0, 0; i < len(arr); i++ {
        if arr[i] != 0 {
            arr[i], arr[j] = arr[j], arr[i]
            j++
        }
    }
    return arr
}
