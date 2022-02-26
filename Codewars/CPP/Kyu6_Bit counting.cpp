unsigned int countBits(unsigned long long n){
  int result = 0; 
  for (int i=63;i>=0;i--) { //63 is the maximum binary length of long long datatype
    //using betwise operator
    int j = n >> i; 
    if (j & 1) result += 1;
  }
  return result;
}
