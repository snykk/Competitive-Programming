using namespace std;
string reverse_letter(const string &str)
{
  string result = "";
  for (int i=str.size()-1;i>=0;i--) {
    if (97 <= int(str[i]) && int(str[i]) <= 122){
    result += str[i];
    }
  } 
  return result;
}
