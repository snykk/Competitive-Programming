int divisors(int n){  
  int count = 0;
  for (int i=1; i <= n;i++) {
    if (n%i == 0) {
      count += 1;
    }
  }
  return count;
}
