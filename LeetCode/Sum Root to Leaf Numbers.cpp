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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int currentNumber) {
        if (!node) return 0;
        
        currentNumber = currentNumber * 10 + node->val;
        
        if (!node->left && !node->right) {
            return currentNumber;
        }
        
        int leftSum = dfs(node->left, currentNumber);
        int rightSum = dfs(node->right, currentNumber);
        
        return leftSum + rightSum;
    }
};
