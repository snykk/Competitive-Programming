class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Using the last row as the initial values for the minimum path sums
        vector<int> dp = triangle[n - 1];

        // Starting from the second last row and working our way up
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                // Update dp[j] with the minimum path sum from triangle[i][j] to the bottom
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0]; // dp[0] now contains the minimum path sum from top to bottom
    }
};