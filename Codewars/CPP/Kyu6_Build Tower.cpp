using namespace std;
class Kata
{
public:
    vector<string> towerBuilder(int nFloors)
    {
      vector<string> result;
      int counter = 1;
      int numSpace;
      char space = ' ';
      char star = '*';
      string construct;
      for (int i=0;i<nFloors;i++) {
        numSpace = nFloors*2 - 1 - counter;
        construct = string(int(numSpace/2), space) + string(int(counter),star) + string(int(numSpace/2),space);
        result.push_back(construct);
        counter += 2;
      }
      return result;
    }
};
