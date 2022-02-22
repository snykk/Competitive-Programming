using namespace std;
bool compare(string s1, string s2)
{
  int sum_s1 = 0;
  int sum_s2 = 0;
  int len1 = s1.length();
  int len2 = s2.length();
  for (int i=0;i<len1;i++){
    if (int(s1[i]) < 65 || (90 < int(s1[i]) && int(s1[i]) < 97) || int(s1[i]) > 122 ){
      sum_s1 = 0;
      break;
    } else if (97 <= int(s1[i]) && int(s1[i])  <= 122){
      sum_s1 += int(s1[i]) - 32;
    } else {
      sum_s1 += int(s1[i]);
    }
  }
  for (int i=0;i<len2;i++){
    if (int(s2[i]) < 65 || (90 < int(s2[i]) && int(s2[i]) < 97) || int(s2[i]) > 122 ) {
      sum_s2 = 0;
      break;
    } else if (97 <= int(s2[i]) && int(s2[i]) <= 122) {
      sum_s2 += int(s2[i]) - 32;
    } else {
      sum_s2 += int(s2[i]);
    }
  }
  return sum_s1 == sum_s2;
}
