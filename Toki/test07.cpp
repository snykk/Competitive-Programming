#include <iostream>
using namespace std;

int main()
{
	int s0, n, d;
	cin >> s0 >> n >> d;
	cout << s0 << endl;
	for (int i = 0; i < n - 1; i++) {
		s0 += d;
		cout << s0 << endl;;
	}
	return 0;
}
