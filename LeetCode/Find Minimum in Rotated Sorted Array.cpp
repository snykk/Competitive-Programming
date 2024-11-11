class Solution {
public:
    // // poor solution and sadly it's work. 
    // // it's not that hard. i think it's a wrong level
    // int findMin(vector<int>& nums) {
    //     int result = INT_MAX;

    //     for (int x : nums) {
    //         if (x <= result) result = x;
    //     }

    //     return result;
    // }
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }

};