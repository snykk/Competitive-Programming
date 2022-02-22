#include <vector>
using namespace std;
vector<unsigned long long> odd_row(unsigned int n) {
  if (n==1) return {1};
  
  vector<unsigned long long> result;
  //patern 1, 5, 11, 19, 29
  long long last_number = 0;
  long long count = 5;
  long long op = n;
  for (long i=2;i<=op;i++){
    last_number = count;
    count += (i+1)*2;
  }
  //each digit in pattern - (n-1)*2
  long long first_number = last_number - (n-1)*2;
  for (long long i=first_number;i<=last_number;i+=2){
    result.push_back(i);
  }
  return result;
}
