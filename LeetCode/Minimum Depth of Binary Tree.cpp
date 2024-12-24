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
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1}); // Start with the root node and depth 1

        while (!q.empty()) {
            TreeNode* current = q.front().first;
            int depth = q.front().second;
            q.pop();

            // Return its depth If we reach a leaf node
            if (!current->left && !current->right) return depth;

            // Push children to the queue with incremented depth
            if (current->left) q.push({current->left, depth + 1});
            if (current->right) q.push({current->right, depth + 1});
        }

        return 0;
    }
};
