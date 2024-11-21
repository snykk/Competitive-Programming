class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dp(n, 0);
        
        // Initialize the DP array
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        // Compute the DP values row by row
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0]; // Update the first column
            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};