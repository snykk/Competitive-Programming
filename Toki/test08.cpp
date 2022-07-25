#include <iostream>
using namespace std;

int main()
{
	int n, d, temp;
	bool acc = false;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == d && !acc) {
			cout << i << endl;
			acc = true;
		}
	} 
	if (!acc) 
		cout << -1 << endl;
}

