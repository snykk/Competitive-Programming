typedef unsigned long long ull;
class SumFct
{
  public:
  static ull perimeter(int n) {
    ull result = 2;
    ull num1 = 1;
    ull num2 = 1;
    ull temporary;
    while (n-1) {
      temporary = num1+num2;
      num2 = num1;
      num1 = temporary;
      result += num1;
      --n;
    }
    return result*4;
  }
};
