class Solution {
public:
    void binarySearch(vector<int> &nums, int n, set<int> &indices, int begin, int end){
        if(begin > end) return;

        if(nums[end] < n) return;

        if(nums[begin] > n) return;

        int mid = (begin + end) / 2;
        if(nums[mid] == n) indices.insert(mid);

        // implement recursive
        binarySearch(nums, n, indices, mid + 1, end);
        binarySearch(nums, n, indices, begin, mid - 1);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if(nums.size() <= 0) return result;

        set<int> indices;
        binarySearch(nums, target, indices, 0, nums.size() - 1);

        if(indices.size() >= 1){
            result[0] = *(indices.begin());
            result[1] = *(indices.rbegin());
        }

        return result;
    }
};