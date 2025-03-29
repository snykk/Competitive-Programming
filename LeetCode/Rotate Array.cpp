#include <vector>
using namespace std;

class Solution {
public:
    // // #1: using modulo and new index
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     k = k % n;
    //     vector<int> temp(n);

    //     for (int i = 0; i < n; i++) {
    //         temp[(i + k) % n] = nums[i];
    //     }

    //     nums = temp;
    // }

    // // #2: reversal algorithm
    // void reverse(vector<int>& nums, int left, int right) {
    //     while (left < right) {
    //         swap(nums[left], nums[right]);
    //         left++;
    //         right--;
    //     }
    // }

    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     k = k % n;

    //     reverse(nums, 0, n - 1);
    //     reverse(nums, 0, k - 1);
    //     reverse(nums, k, n - 1);
    // }
    // #3: copy and paste
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp(nums.end() - k, nums.end());
        temp.insert(temp.end(), nums.begin(), nums.end() - k);
        nums = temp;
    }
};
