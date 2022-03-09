#include <string>
#include <list>
using namespace std;

string yuhu_itsme(string a, string b){
	string result = "";
	list<int> arr;
	int temporary = 0;
	int count = 0;
	for (int i=a.length()-1;i>=0;i--) {
		count = int(a[i]) + int(b[i]) + temporary - 96 ;
		if (count >= 10 ) {
			temporary = 1;
			arr.push_front(count%10);
		} else {
			arr.push_front(count);
			temporary=0;
		}
	}
	if (temporary == 1){
		arr.push_front(1);
	}
	for (auto inc = arr.begin();inc != arr.end();inc++) {
		result += to_string(*inc);
	}
	return result;
}

string sum_strings(const string& a, const string& b) {
  string A = a;
	string B = b;
	string result = "";
	int lenA = A.length();
	int lenB = B.length();
	if (lenA > lenB) {
		B.insert(0,lenA-lenB,'0');
	} else A.insert(0,lenB-lenA,'0');
	result = yuhu_itsme(A,B);
	return result;
}
