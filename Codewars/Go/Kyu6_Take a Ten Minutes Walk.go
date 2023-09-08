package kata


func IsValidWalk(walk []rune) bool {
	var coordinateHor int
	var coordinateVer int

	for _, char := range walk {
		switch char {
		case 'n':
			coordinateHor++
		case 's':
			coordinateHor--
		case 'e':
			coordinateVer--
		case 'w':
			coordinateVer--
		}
	}

	return coordinateHor == 0 && coordinateVer == 0

}
