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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr, *curr = root;

        while (curr) {
            if (!curr->left) {
                // process the current node
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                // find the rightmost node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right && pre->right != curr) {
                    pre = pre->right;
                }

                if (!pre->right) {
                    // establish a thread to the current node
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    // remove the thread and process the current node
                    pre->right = nullptr;
                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        // swap the values of the two misplaced nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};