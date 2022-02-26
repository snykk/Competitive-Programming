int countSmileys(vector<string> arr)
{
  int result = 0;
  for (auto i:arr) {
    if (i.length()==2&&(i[0]==':'||i[0]==';')&&(i[1]==')'||i[1]=='D')) result += 1;
    else if (i.length()==3&&(i[0]==':'||i[0]==';')&&(i[1]=='~'||i[1]=='-')&&(i[2]==')'||i[2]=='D')) result += 1;
  }
  return result;
}
