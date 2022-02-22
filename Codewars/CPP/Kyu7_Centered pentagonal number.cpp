long pentagonal(long n) {
  if (n <= 0) {
    return -1;
  }
  long res = 1;
  long i = 1;
  while (i<n){
    res += 5*i;
    i ++;
  }
  return res;
}

