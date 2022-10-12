package kata

func ValidParentheses(parens string) bool {
  var openBracket,closedBracket int = 0,0
  
  if parens == "" {
    return true
  } else if string(parens[0]) == ")" || string(parens[len(parens)-1]) == "(" {
    return false
  }
  
  for _, char := range parens {
    if closedBracket > openBracket {
      return false
    }
    
    switch char {
      case '(':
        openBracket++
      case ')':
        closedBracket++
    
    }
  }
  
  return openBracket == closedBracket
}