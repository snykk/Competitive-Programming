#include <vector>
using namespace std;

int score(const vector<int>& dice) {
  int result = 0;
  vector<int> temp = {0,0,0,0,0,0};
  for (int i=0;i<dice.size();i++) {
    temp[dice[i]-1] += 1;
  }
  if (temp[0] >= 3 ) {
    result += 1000;
  } else if (temp[4] >= 3) {
    result += 500;
  }
  result += 100*(temp[0]%3);
  result += 50*(temp[4]%3);
  
  for (int i=1;i<6;i++) {
    if (temp[i] >= 3 && i != 4) result += (i+1)*100;
  }
  for (auto i:temp) cout << i << " ";
  cout << endl;
  return result;
  
}
