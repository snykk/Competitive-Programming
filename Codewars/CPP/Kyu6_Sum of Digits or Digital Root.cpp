#include <string>
using namespace std;
int digital_root(int n)
{
  if (n==0) return 0;
  int result = 0;
  string nStr = to_string(n);
  int len = nStr.length();
  while (true) {
   for (int i=0;i<len;i++) {
    result += int(nStr[i]) - 48;
    }
    if (result < 10) {
      break;
    }
    n = result;
    result = 0;
    nStr = to_string(n);
    len = nStr.length();
  }
  
  return result;
}
