long zeros(long n) {
  // literacy => https://www.handakafunda.com/number-of-trailing-zeros/
  long result = 0;
  while (n >=5) {
    n /= 5;
    result += n;
  }
  return result;
}
