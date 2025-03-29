class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        deque<int> dq;

        while (left <= right) {
            int l = abs(nums[left]), r = abs(nums[right]);

            if (l < r) {
                dq.push_front(pow(r, 2));
                right--;
            } else {
                dq.push_front(pow(l, 2));
                left++;
            }
        }

        return vector<int>(dq.begin(), dq.end());
    }
};