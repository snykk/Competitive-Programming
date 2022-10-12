class Solution {
public:
    int romanToInt(string s) {
        int result =0;
        unordered_map<char,int> mapHelper{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        
        for(int index=0;index<s.size();index++){
            if(mapHelper[s[index]] < mapHelper[s[index+1]]) result -= mapHelper[s[index]];
            else result += mapHelper[s[index]];
        }
        
        return result;
    }
};