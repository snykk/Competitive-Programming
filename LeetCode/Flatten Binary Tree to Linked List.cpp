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
    // // iterative solution (using stack)
    // void flatten(TreeNode* root) {
    //     if (!root) return;

    //     stack<TreeNode*> s;
    //     s.push(root);

    //     while (!s.empty()) {
    //         TreeNode* current = s.top();
    //         s.pop();

    //         // Push right and left children onto the stack (right first to process left first)
    //         if (current->right) {
    //             s.push(current->right);
    //         }
    //         if (current->left) {
    //             s.push(current->left);
    //         }

    //         // Update the current node's pointers
    //         if (!s.empty()) {
    //             current->right = s.top();
    //         }
    //         current->left = nullptr;
    //     }
    // }

    // recursive solution
    void flatten(TreeNode* root) {
        // Base case
        if (!root) return;

        // Recursively flatten the left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Save the right subtree
        TreeNode* rightSubtree = root->right;

        // Move the left subtree to the right
        root->right = root->left;
        root->left = nullptr;

        // Traverse to the end of the new right subtree
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }

        // Attach the saved right subtree
        current->right = rightSubtree;
    }
};
