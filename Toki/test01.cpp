#include <iostream>
#include <cassert>
using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	assert(1<= a.length() <= 1000);
	assert(1<= b.length() <= 1000);
	int len = a.length();
	int loc;
	for (int i=0;i<len;i++) {
		if (a[i] != b[i]) {
			loc = i;
			break;
		}
	}
	a = a.substr(0,loc) + a.substr(loc+1, len);
	if (a == b) cout << "Tentu saja bisa!" << endl;
	else cout << "Wah, tidak bisa :(" << endl;
	return 0;
}
