// origin name of kyu : Kyu6_Does my number look big in this?
#include <cmath>
using namespace std;

bool narcissistic( int value ){
	string strValue = to_string(value);
	int len = strValue.length();
	int sum = 0;
	for (int i=0;i<len;i++) {
		sum += pow(strValue[i] - '0', len);
	}
  return sum == value;
}

