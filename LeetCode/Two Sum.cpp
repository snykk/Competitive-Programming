class Solution {
    public:
        // greedy approach (bruteforce) -> Big(O) = O(n^2)
        // vector<int> twoSum(vector<int>& nums, int target) {
        //     int len = nums.size();
        //     vector<int> result;
        //     for (int i=0;i<len-1;i++) {
        //         for (int j=i+1;j<len;j++) {
        //             if (nums[i] + nums[j] == target) {
        //                 result = {i,j};
        //             }
        //         }
        //     }
        //     return result;
        // }

        // using hashmap -> Big(O) = O(n)
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> ump;
    
            for (int i = 0; i < nums.size(); i++) {
                int diff = target - nums[i];
    
                if (ump.find(diff) != ump.end()) {
                    return {ump[diff], i};
                }
    
                ump[nums[i]] = i;
            }
    
            return {};
        }
    };