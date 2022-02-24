using namespace std;
vector<int> deleteNth(vector<int> arr, int n)
{
  vector<int> result;
  int len = arr.size();
  for ( int i=0; i<len; i++ ) {
    if (count(result.begin(), result.end(), arr[i]) < n) result.push_back(arr[i]);
  }
  return result;
}
