#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(const string & str)
{
   vector<int> d;
   stringstream ss(str);
   string temp;   
   while ( ss >> temp )
   {
       stringstream st(temp);
       while ( st  )
       {
           int i;
           if (st >> i)
               d.push_back(i);
           else
           {
               st.clear();
               st.get();
           }
        }               
   }
   return d;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
