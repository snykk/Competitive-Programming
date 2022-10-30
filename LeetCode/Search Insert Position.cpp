class Solution {
public:
    int binarySearch(vector<int>&nums,int begin, int end, int target) {
        // BASE
        if(target<=nums[0]) return 0;
        if(target==nums[nums.size()-1]) return nums.size()-1;
        if(target>nums[nums.size()-1]) return nums.size();

        if(begin<=end) {
            int mid=begin+(end-begin) / 2;
            if(nums[mid]==target) return mid;

            if(nums[mid]>target && nums[mid-1]<target) return mid;

            if(nums[mid]>target && nums[mid+1]<target) return mid;

            else if(nums[mid]>target) return binarySearch(nums,begin,mid-1,target);

            // RECURSIVE
            return binarySearch(nums,mid+1,end,target);
        }

        return -1;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};