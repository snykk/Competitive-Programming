using namespace std;
string to_camel_case(string text) {
  string result = "";
	int len = text.length();
	for (int i=0;i<len;i++) {
		int dec = int(text[i]);
		if ( (65 <= dec && dec <= 90) || (97 <= dec && dec <= 122) ) {
			result += text[i];
		} else {
			i += 1;
			result += toupper(text[i]);
		}
	}
  return result;
}
