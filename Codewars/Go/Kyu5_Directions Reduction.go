package kata

func DirReduc(arr []string) []string {
  mapHelper := map[string]string {
     "NORTH":"SOUTH",
     "SOUTH":"NORTH",
     "WEST":"EAST",
     "EAST":"WEST",
  }
  var result = []string{}
  
  for _, item := range arr {
    if len(result) != 0 && mapHelper[string(item)] == result[len(result)-1] {
       result = result[:len(result)-1]
    } else {
      result = append(result, string(item))
    }
  }
  
  return result
}