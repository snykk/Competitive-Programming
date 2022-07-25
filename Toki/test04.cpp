#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	std::string result = (0 <= n && n <= 100) ? "YA" : "TIDAK";
	std::cout << result;
	return 0;
}
