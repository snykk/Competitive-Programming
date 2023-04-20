class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        // binary search approach
        int left = 1, right = x;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
