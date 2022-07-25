#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, temp;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++){
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = arr.size()-1; i >= 1; i--) {
		cout << arr[i] << ',';
	}
	cout << arr[0];
	return 0;
}
