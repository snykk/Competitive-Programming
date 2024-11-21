class Solution {
public:
    int uniquePaths(int m, int n) {
        // Use a 1D array for space optimization
        vector<int> dp(n, 1);

        // Compute unique paths for each row
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1]; // Update current cell with sum of top and left
            }
        }

        return dp[n - 1]; // The bottom-right corner value
    }

};