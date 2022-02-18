function makePassword(phrase) {
  const arr = phrase.split(" ");
  var str = "";
  for (let i = 0; i < arr.length; i++) {
    if (arr[i][0] === 'o' ||  arr[i][0] === 'O'){
      str += '0';
    } else if (arr[i][0] === 'i' ||  arr[i][0] === 'I') {
      str += '1';
    } else if (arr[i][0] === 's' ||  arr[i][0] === 'S'){
      str += '5';
    } else {
      str += arr[i][0];
    }
  }
  return str;
}

