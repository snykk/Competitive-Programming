#include <string>
using namespace std;
string fakeBin(string str){
  string result;
  int len = str.length();
  for (int i=0;i<len;i++) {
    int number = str[i] - '0';
    if (number < 5){
      result += '0';
    } else {
      result += '1';
    }
  }
  return result;
}

