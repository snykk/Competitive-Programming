class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;

        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());

        // Start backtracking
        backtrack(0, nums, currentSubset, result);
        return result;
    }

private:
    void backtrack(int start, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(currentSubset);

        // Explore further subsets
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;

            // Include the current element
            currentSubset.push_back(nums[i]);

            // Recurse with the next index
            backtrack(i + 1, nums, currentSubset, result);

            // Backtrack by removing the last element
            currentSubset.pop_back();
        }
    }
};
