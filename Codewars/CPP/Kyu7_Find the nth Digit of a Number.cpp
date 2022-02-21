#include <string>
using namespace std;
int findDigit(int num, int nth){
                            //future coding style
  if (num < 0) num = num * -1;        if               (nth<=0) return -1;
      string numStr = to_string(num); if (numStr.length()<nth) return 0;
                    return numStr[numStr.length()-nth] - '0';
}
