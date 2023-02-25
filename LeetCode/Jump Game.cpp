class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int curr_farthes = 0; 
        
        for (int i = 0; i < n; i++) {
            if (curr_farthes < i) return false; 
            curr_farthes = max(curr_farthes, i + nums[i]);
        }
        
        return true; // we can reach the end
    }
};
