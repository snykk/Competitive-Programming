class Solution {
public:
    bool check(char &charP, char &charS) {
        if (charP == '.') return true;
        
        return charP == charS;
    }
    
    
    bool isMatch(string s, string p) {
        int lengthP = p.size(), lengthS = s.size();
        vector<vector<bool>> myVec(lengthP + 1, vector<bool>(lengthS + 1, false)); 
        myVec[0][0] = true;

        for (int i = 1; i <= lengthP; i++) {
            if (p[i - 1] == '*') myVec[i][0] = myVec[i - 2][0];

            for (int j = 1; j <= lengthS; j++) {
                if (check(p[i - 1], s[j - 1]))   myVec[i][j] = myVec[i - 1][j - 1];

                else if (p[i - 1] == '*') myVec[i][j] = myVec[i - 2][j] || (check(p[i - 2], s[j - 1]) && myVec[i][j - 1]);
            }
        }

        return myVec[lengthP][lengthS];
    }
};