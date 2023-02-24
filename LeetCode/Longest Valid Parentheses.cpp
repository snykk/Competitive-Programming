class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        
        int n = s.length();
        int max_length = 0;
        int dp[n];
        fill(dp, dp+n, 0);

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                } else if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                    dp[i] = dp[i-1] + ((i-dp[i-1]-2 >= 0) ? dp[i-dp[i-1]-2] : 0) + 2;
                }
                max_length = max(max_length, dp[i]);
            }
        }

        return max_length;
    }
};