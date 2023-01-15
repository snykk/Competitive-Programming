func lengthOfLastWord(s string) int {
    cleanString := strings.TrimSpace(s)
    arr := strings.Split(cleanString, " ")

    return len(arr[len(arr)-1])
}