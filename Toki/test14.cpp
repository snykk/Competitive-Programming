#include <iostream>

int main()
{
	int quest;
	std::cin >> quest;
	std::string result;
	result = (quest == 2 || quest == 3 || quest == 5) ? "YES" : "NO";
	std::cout << result << std::endl;	
}
