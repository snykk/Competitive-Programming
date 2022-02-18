using namespace std;

class SequenceSum{
  int count;
  public:
  SequenceSum (int);
  string showSequence();
  
};

string SequenceSum::showSequence(){
  if (-15 < count && count < 0) {
    return to_string(count) +"<0";    
  } else if (count == 0){
    return "0=0";
  }
  string result;
	int  i=0;
  int sum=0;
	while (i<count) {
		result += to_string(i) + '+';
		sum += i;
		i ++;
	}
	result += to_string(i) ;
  sum += i;
  result += " = " + to_string(sum);
	return result;;
}

SequenceSum::SequenceSum (int c) {
  count = c;
}
