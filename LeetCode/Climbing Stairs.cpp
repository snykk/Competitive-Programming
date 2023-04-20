class Solution {
public:
    // consume more memory
    // int climbStairs(int n) {
    //     vector<int> dp(n+1);
    //     dp[0] = dp[1] = 1;
    //     for(int i=2; i<=n; i++) {
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

    int climbStairs(int n) {
        int num1 = 1, num2 = 1;
        for(int i=2; i<=n; i++) {
            int temp = num2;
            num2 = num1 + num2;
            num1 = temp;
        }
        return num2;
    }
};