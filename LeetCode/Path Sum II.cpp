/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result; // To store all paths
        vector<int> currentPath; // To store the current path
        dfs(root, targetSum, currentPath, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) return; // Base case: if the node is null, return.

        // Add the current node to the path
        currentPath.push_back(node->val);

        // Check if it is a leav node and the path sum equals targetSum
        if (!node->left && !node->right && targetSum == node->val) {
            result.push_back(currentPath); // Add the current path to the result
        } else {
            // Recur for the left and right children with the updated targetSum
            dfs(node->left, targetSum - node->val, currentPath, result);
            dfs(node->right, targetSum - node->val, currentPath, result);
        }

        // Backtrack - remove the current node from the current path
        currentPath.pop_back();
    }
};