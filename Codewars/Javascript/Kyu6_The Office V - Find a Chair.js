function meeting(x, need){
  if (need===0) return 'Game On';
  var demand = need;
  var result = [];
  for (let i=0;i<x.length;i++) {
    if (demand === 0) break;
    let free_chair = x[i][1]-x[i][0].length;
    if (free_chair < 0) {
      free_chair = 0;
    } else if (free_chair > demand) free_chair = demand;
    result.push(free_chair);
    demand = demand - free_chair;
  }
  if (demand > 0) return 'Not enough!';
  return result;
}

