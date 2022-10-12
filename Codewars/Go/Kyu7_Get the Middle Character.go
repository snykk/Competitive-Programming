package kata

func GetMiddle(s string) string {
	var div int
	div = len(s) / 2
	if len(s)%2 == 0 {
    return s[div-1 : div+1]
	} 
  
	return s[div : div+1]
}