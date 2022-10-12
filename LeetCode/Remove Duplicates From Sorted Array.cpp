class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, j = 1, length = nums.size();
        
        for(int i = 1; i < length; i++){
            if(nums[i] != nums[i-1]){
                nums[j] = nums[i];
                count++;
                j++;
            }
        }
        return ++count;
    }
};