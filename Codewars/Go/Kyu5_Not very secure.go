package kata

func alphanumeric(str string) bool {
  if str == "" {
    return false
  }
  
  for _, char := range str {
    if 48 <= char && char <= 57 || 65 <= char && char <= 90 || 97 <= char && char <= 122 {
      continue
    }
    
    return false
  }
  
  return true
}