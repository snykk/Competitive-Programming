class Solution {
public:
    // // lazy brute force with time complexity O(n)
    // bool search(vector<int>& nums, int target) {
    //     for (int num : nums) {
    //         if (num == target) return true;
    //     }

    //     return false;
    // }

    // binary search with time complexity O(log n) it's mean much better
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return true;
            }
            
            // handle duplicates
            if (nums[m] == nums[l] && nums[m] == nums[r]) {
                l++;
                r--;
            } else if (nums[l] <= nums[m]) { // l half is sorted
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else { // r half is sorted
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        
        return false;
    }
};