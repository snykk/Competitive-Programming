using namespace std;
class Kata
{
public:
    vector<int> sortArray(vector<int> array)
    {
      vector<int> num;
      vector<int> loc;
      int lenArr = array.size();
      for (int i=0;i<lenArr;i++) {
        if (array[i]%2 != 0) {
          num.push_back(array[i]);
          loc.push_back(i);
        }
      }
      sort(num.begin(), num.end());
      int lenNum = num.size();
      for (int i=0;i<lenNum;i++) {
        array[loc[i]] = num[i];
      }
      return array;
    }
};
