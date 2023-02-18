class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                long long new_target = target - nums[i] - nums[j];
                int left = j+1, right = n-1;
                while (left < right) {
                    long long sum = nums[left] + nums[right];
                    if (sum == new_target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left; --right;
                        while (left < right && nums[left] == nums[left-1]) ++left;
                        while (left < right && nums[right] == nums[right+1]) --right;
                    } else if (sum < new_target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return res;
    }
};
