#include <string>
#include <vector>  
#include <sstream>  
using namespace std;

string highAndLow(const string& numbers){
  string numStr;
  vector<int> lst;
  stringstream quest(numbers); 
  while (getline(quest, numStr, ' ')) {
    int numInt = stoi(numStr);
    lst.push_back(numInt);
  }
  sort(lst.begin(), lst.end());
  return to_string(lst[lst.size()-1]) + " " + to_string(lst[0]);
}
