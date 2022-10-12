package kata

import (
  "fmt"
)

func validate(num int) int {
  switch {
    case num < 0: return 0
    case num > 255: return 255
    default: return num
  }
}

func RGB(r, g, b int) string {
  return fmt.Sprintf("%02X%02X%02X", validate(r), validate(g), validate(b))
}