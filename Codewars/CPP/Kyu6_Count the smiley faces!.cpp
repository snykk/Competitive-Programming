/*
 * Given an array (arr) as an argument complete the function countSmileys that should return the 
 * total number of smiling faces.
 * 
 * Rules for a smiling face:
 * 1. Each smiley face must contain a valid pair of eyes. Eyes can be marked as : or ;
 * 2. A smiley face can have a nose but it does not have to. Valid characters for a nose are - or ~
 * 3. Every smiling face must have a smiling mouth that should be marked with either ) or D
 * 
 * No additional characters are allowed except for those mentioned. 
 * Valid smiley face examples: :) :D ;-D :~)
 * Invalid smiley faces: ;( :> :} :]
 * 
 * Examples
 * countSmileys([':)', ';(', ';}', ':-D']);       // should return 2;
 * countSmileys([';D', ':-(', ':-)', ';~)']);     // should return 3;
 * countSmileys([';]', ':[', ';*', ':$', ';-D']); // should return 1;
 */
int countSmileys(vector<string> arr)
{
  int result = 0;
  for (auto i:arr) {
    if (i.length()==2&&(i[0]==':'||i[0]==';')&&(i[1]==')'||i[1]=='D')) result += 1;
    else if (i.length()==3&&(i[0]==':'||i[0]==';')&&(i[1]=='~'||i[1]=='-')&&(i[2]==')'||i[2]=='D')) result += 1;
  }
  return result;
}

//guys on the top
#include <regex>

int countSmileys(std::vector<std::string> arr)
{
  int count = 0;
  std::regex smiles_regex("[:|;](-|~)?[)|D]");
  
  for (auto &smile : arr) {
    if (std::regex_match(smile, smiles_regex))
      count++;
  }

  return count;
}
