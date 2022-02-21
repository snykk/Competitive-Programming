function solution($str, $ending) {
  return substr("$str",strlen($str)-strlen($ending)) == $ending;
}
