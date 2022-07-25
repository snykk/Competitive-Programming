#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

int main()
{
	long n;
	int tempInt, len;
	string tempStr;
	cin >> n;
	assert(0 <= n && n <= 10000000);
	while (n--) {
		cin >> tempInt;
		tempStr = to_string(tempInt);
		reverse(begin(tempStr), end(tempStr));
		len = tempStr.length();
		for (int i = 0; i < len; i++) {
			if (int(tempStr[i]) != 48) {
				tempStr = tempStr.substr(i, len);
				break;
			}
		}
		tempInt = stoi(tempStr);
		cout << tempInt << endl;
	}
}


