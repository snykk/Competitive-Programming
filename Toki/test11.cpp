#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string s;
	getline(cin, s);
	vector<string> arr;
	string temp = "";
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == ' '){
			arr.push_back(temp);
			temp = "";
		} else
			temp += s[i];
	}
	arr.push_back(temp); 
	if (arr[1] == "+") {
		cout << stoi(arr[0]) + stoi(arr[2]) << endl;
	} else if (arr[1] == "-") {
		cout << stoi(arr[0]) - stoi(arr[2]) << endl;
	} else if (arr[1] == "*") {
		cout << stoi(arr[0]) * stoi(arr[2]) << endl;
	} else if (arr[1] == "<") {
		if (stoi(arr[0]) < stoi(arr[2]))
			cout << "benar" << endl;
		else 
			cout << "salah" << endl;
	} else if (arr[1] == ">") {
		if (stoi(arr[0]) > stoi(arr[2]))
			cout << "benar" << endl;
		else 
			cout << "salah" << endl;
	} else if (arr[1] == "=") {
		if (stoi(arr[0]) == stoi(arr[2]))
			cout << "benar" << endl;
		else 
			cout << "salah" << endl;
	}
	return 0;
}
