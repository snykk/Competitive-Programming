#include <cstdlib>
using namespace std;
int FindOutlier(vector<int> arr)
{
  int cek=0;
  for (int i=0;i<3;i++) {
    if (arr[i]%2 ==0 ) cek += 5;
    else cek += 2;
  }
  if (cek > 10) cek  =0;
  else cek = 1;
  for (int i=0;i<arr.size();i++) {
    if (abs(arr[i])%2!=cek) {
      return arr[i];
    }
  }
}
