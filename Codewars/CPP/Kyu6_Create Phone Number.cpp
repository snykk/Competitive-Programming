#include <string>
using namespace std;
string createPhoneNumber(const int arr [10]){
  return '(' + to_string(arr[0]) + to_string(arr[1]) + to_string(arr[2]) + ") " + to_string(arr[3]) + to_string(arr[4]) + to_string(arr[5]) + '-' + to_string(arr[6]) + to_string(arr[7]) + to_string(arr[8]) + to_string(arr[9]);
}
