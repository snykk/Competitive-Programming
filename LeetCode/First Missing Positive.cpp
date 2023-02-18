class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // move all non-positive numbers to the end of the array
        int i = 0;
        while (i < n) {
            if (nums[i] <= 0) {
                swap(nums[i], nums[n-1]);
                n--;
                continue;
            }
            i++;
        }

        // use the array as a hash set to mark existing positive numbers
        for (i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (idx < n && nums[idx] > 0) nums[idx] = -nums[idx];
        }

        // find the first missing positive number
        for (i = 0; i < n; i++) {
            if (nums[i] > 0) return i+1;
        }

        return n+1;
    }
};
