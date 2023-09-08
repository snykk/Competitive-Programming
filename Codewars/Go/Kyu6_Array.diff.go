package kata

func ArrayDiff(a, b []int) []int {
	var res []int
	for _, i := range a {
		var isPresent = false
		for _, j := range b {
			if i == j {
				isPresent = true
				break
			}
		}

		if !isPresent {
			res = append(res, i)
		}
	}

	return res
}
