#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

int targetGame(const vector<int>& values) {
  // your code goes here
  int num1 = 0, num2 = 0;
  int temp;
  for(auto i : values)
  {
	  temp = num1;
	  num1 = num2;
	  num2 = max(temp+i,num2);
  }
  return max(num1,num2);
}
