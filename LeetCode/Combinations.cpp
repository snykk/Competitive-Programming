class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(1, n, k, combination, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, vector<int>& combination, vector<vector<int>>& result) {
        // If the combination is of the desired length, add it to the result
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i <= n; i++) {
            // Add the current number to the combination
            combination.push_back(i);

            // Recurse with the next number
            backtrack(i + 1, n, k, combination, result);

            // Backtrack by removing the last added number
            combination.pop_back();
        }
    }
};
