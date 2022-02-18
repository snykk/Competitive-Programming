#include <vector>
using namespace std;
std::vector<int> generate_integers(int m, int n)
{
  vector<int> result;
  for (int i=m;i<=n;i++){
    result.push_back(i);
  }
  return result;
}