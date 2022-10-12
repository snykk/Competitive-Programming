class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, result = 0;
        unordered_map<char, int> mapp;
        while(j < s.size()) {
            mapp[s[j]]++;
            if(mapp.size() == j - i + 1) {
                result = max(result, j - i + 1);
                j++;
                continue;
            }

            while(mapp.size() < j - i + 1) {  
                mapp[s[i]]--;
                if(mapp[s[i]] == 0)
                    mapp.erase(s[i]);
                i++;
            }

            j++;
        }
        return result;
    }
};