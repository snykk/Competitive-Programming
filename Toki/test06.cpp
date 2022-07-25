#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	std::cout << n/3600 << std::endl;
	std::cout << (n%3600)/60 << std::endl;
	std::cout << (n%3600)%60 << std::endl;
}
