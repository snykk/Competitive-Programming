class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr_combination;
        backtrack(candidates, target, result, curr_combination, 0);
        return result;
    }
    
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& curr_combination, int start) {
        if (target == 0) {
            result.push_back(curr_combination);
            return;
        }
        
        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            curr_combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, curr_combination, i+1);
            curr_combination.pop_back();
        }
    }
};
