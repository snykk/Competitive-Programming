class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            // skip duplicates
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // skip duplicates
                    while (left < right && nums[left] == nums[left+1])
                        left++;
                    while (left < right && nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
 
    }
};