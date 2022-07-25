#include <iostream>
#include <cassert>

int main()
{
	int n;
	std::cin >> n;
	assert(10 <= n && n <= 1000);
	if (n/2 + n/3 + n/4 > n)
		std::cout << n/2 + n/3 + n/4 << std::endl;
	else 
		std::cout << n << std::endl;
}
