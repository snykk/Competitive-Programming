using namespace std;
class Kata
{
public:
    vector<string> sortByLength(vector<string> array)
    {
      int len = array.size();
      int inc = 0;
      while (inc < len-1) {
       for (int i = 0; i < len-1; i++) {
         if (array[i].length() > array[i+1].length()) {
           string temp = array[i];
           array[i] = array[i+1];
           array[i+1] = temp;
         }
        }
        inc ++;
      }
      return array;
    }
};

