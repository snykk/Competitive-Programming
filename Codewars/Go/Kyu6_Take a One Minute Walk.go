package kata


func IsValidWalk(walk []rune) bool {
  if len(walk) != 10 {
    return false
  }
  
	var coordinateHor int = 0
	var coordinateVer int = 0

	for _, char := range walk {
		switch char {
		case 'n':
			coordinateHor++
		case 's':
			coordinateHor--
		case 'e':
			coordinateVer++
		case 'w':
			coordinateVer--
		}
	}

	return coordinateHor == 0 && coordinateVer == 0

}
