class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int it;
        int check = s[0].length();
        int length = s.size();
        for(int i = 1; i < length; i++){
            it = 0;
            while(it < s[i].length() && s[i][it] == s[0][it]){
                it++;                
            }
            
            check = min(check, it);
        }
        return s[0].substr(0, check);
    }
};