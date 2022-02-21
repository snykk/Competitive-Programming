// origin name of kyu: Kyu7_Odd or Even? Determine that!
int Odd_or_Even(unsigned int n) { 
  if (n%2==1)return 2;
  else if ((n/2)%2==1) return 1;
  else if ((n/2)%2==0) return 0;
}
