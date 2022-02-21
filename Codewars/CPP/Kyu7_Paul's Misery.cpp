#include <string> 
#include <vector>
using namespace std;
string paul(const vector<string>& x) {
  int score = 0;
  for (int i=0;i<x.size();i++) {
    if (x[i] == "kata") score += 5;
    else if (x[i] == "Petes kata") score += 10;
    else if (x[i] == "eating") score += 1;
  }
  if (score < 40) return "Super happy!";
  else if (score < 70) return "Happy!";
  else if (score < 100) return "Sad!";
  else return "Miserable!";
}
