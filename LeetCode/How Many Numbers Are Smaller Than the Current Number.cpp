class Solution {
    public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
            unordered_map<int, int> ump;
            vector<int> temp = nums;
            vector<int> result;
    
            sort(temp.begin(), temp.end());
    
            for (int i = 0; i < temp.size(); i++ ) {
                if (!ump.contains(temp[i])) {
                    ump[temp[i]] = i;
                }
            }
    
            for (int i = 0; i < nums.size(); i++) {
                result.push_back(ump[nums[i]]);
            }
    
            return result;
        }
    };