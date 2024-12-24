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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    // Helper function to check the height of the tree
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        // Recursively check the height of left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Left subtree is not balanced

        // Recursively check the height of right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Right subtree is not balanced

        // If the current node is not balanced, return -1
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // Return the height of the current node
        return max(leftHeight, rightHeight) + 1;
    }
};