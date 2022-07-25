#include <iostream>
#include <cassert>
using namespace std;

int main()
{
	string pattern;
	int n;
	cin >> pattern >> n;
	assert (1<=n && n<=100);
	assert (pattern.length() <= 100);
	int loc = pattern.find('*');
	int rightPatternIndex = pattern.length() - 1;
	string word;
	int rightWordIndex;
	bool cek;
	while (n) {
		cek = true;
		cin >> word;
		rightWordIndex = word.length() - 1;
		if (word.length() < pattern.length()-1) {
			--n;
			continue;
		}
		for (int j=0;j<loc;j++) {
			if (word[j] != pattern[j]) {
				cek = false;
				break;
			}
		}
		for (int j=0;j<rightPatternIndex - loc;j++) {
			if (word[rightWordIndex - j] != pattern[rightPatternIndex - j]) {
				cek = false;
				break;
			}
		}
		if (cek) cout << word << endl;
		--n;
	}
}
