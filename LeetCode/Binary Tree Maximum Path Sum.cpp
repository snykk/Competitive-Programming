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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; 
        
        maxPathSumUtil(root, maxSum);

        return maxSum;
    }
    
private:
    int maxPathSumUtil(TreeNode* node, int& maxSum) {
        if (!node) return 0; 
        
        int leftMax = max(0, maxPathSumUtil(node->left, maxSum)); 
        int rightMax = max(0, maxPathSumUtil(node->right, maxSum));
        
        maxSum = max(maxSum, leftMax + rightMax + node->val);
        
        return max(leftMax, rightMax) + node->val;
    }
};