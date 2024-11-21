class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the start or end point is an obstacle, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }

        // Create a 1D DP array initialized to 0
        vector<int> dp(n, 0);
        dp[0] = 1; // Start point

        // Compute the unique paths row by row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // Obstacle cell
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // Add paths from the left cell
                }
            }
        }

        return dp[n - 1]; // Bottom-right corner value
    }
};