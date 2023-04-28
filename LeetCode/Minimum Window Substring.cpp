class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> fT, fS;
        int l = 0, r = 0, sLen = s.length(), tLen = t.length();
        int count = 0, minLen = sLen + 1, minLeft = -1;
        
        for (char c : t) fT[c]++;
        
        while (r < sLen) {
            char currChar = s[r];
            if (fT.count(currChar)) {
                fS[currChar]++;
                if (fS[currChar] <= fT[currChar]) {
                    count++;
                }
            }

            r++;

            while (count == tLen) {
                if (r - l < minLen) {
                    minLen = r - l;
                    minLeft = l;
                }
                
                char leftChar = s[l];

                if (fT.count(leftChar)) {
                    fS[leftChar]--;
                    if (fS[leftChar] < fT[leftChar]) {
                        count--;
                    }
                }
                
                l++;
            }
        }
        
        if (minLeft == -1) return "";
        
        return s.substr(minLeft, minLen);
    }
};
