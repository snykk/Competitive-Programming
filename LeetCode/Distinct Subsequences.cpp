class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();

        // edge case: if t is longer than s, no subsequences can match
        if (n > m) return 0;

        // use a 1D DP array to store counts
        vector<double> dp(n + 1, 0); // use `double` to prevent overflow
        dp[0] = 1; // base casw: an empty `t` can always be formed

        // iterate through `s` and update DP values
        for (int i = 1; i <= m; ++i) {
            // update the DP array in reverse to avoid overwriting
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};
