#include <iostream>

int main()
{
	int p, q, result;
	std::cin >> p >> q;
	result = ((p*p + q*q + 1)%4 == 0) ? (p*p + q*q + 1)/4 : -1;
	std::cout << result << std::endl;
 	return 0;
}
