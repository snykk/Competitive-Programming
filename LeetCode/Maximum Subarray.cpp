class Solution {
public:
    // kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN; 
        
        for (int num : nums) {
            currentSum += num;
            maxSum = max(maxSum, currentSum);
            if (currentSum < 0) {
                currentSum = 0; 
            }
        }
        return maxSum;
    }
};