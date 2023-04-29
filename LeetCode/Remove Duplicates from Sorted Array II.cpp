class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int threshold = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                if (threshold == 2) continue;
                threshold++;
            } else {
                threshold = 1;
            }
            nums[res++] = nums[i];
        }
        return res;
    }
};