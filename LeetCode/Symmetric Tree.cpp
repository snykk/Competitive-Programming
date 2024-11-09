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
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;    // Both nodes are null
        if (!left || !right) return false;   // One node is null, the other is not
        return (left->val == right->val) &&  // Check values
               isMirror(left->left, right->right) &&  // Left subtree of `left` and right subtree of `right`
               isMirror(left->right, right->left);    // Right subtree of `left` and left subtree of `right`
    }
    
    bool isSymmetric(TreeNode* root) {
        // Recursive solution
        return isMirror(root->left, root->right);
    }
};