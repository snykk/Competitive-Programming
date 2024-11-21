class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(0, nums, currentSubset, result);
        return result;
    }

private:
    void backtrack(int index, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(currentSubset);

        // Explore further subsets
        for (int i = index; i < nums.size(); i++) {
            // Include the current element
            currentSubset.push_back(nums[i]);

            // Recurse with the next index
            backtrack(i + 1, nums, currentSubset, result);

            // Backtrack by removing the last element
            currentSubset.pop_back();
        }
    }
};
