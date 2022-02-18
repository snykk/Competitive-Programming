#include <bits/stdc++.h>
using namespace std;
int sumTriangularNumbers(int n) {
  vector<int> arr;
  int counter = 0;
  for (int i=1;i<=n;i++){
    counter += i;
    arr.push_back(counter);
  }
  return accumulate(arr.begin(), arr.end(), 0);
}
