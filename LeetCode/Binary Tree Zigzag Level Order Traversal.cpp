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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // insert into the level vector based on the current direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                // enqueue the left and right children
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // toggle the direction
            leftToRight = !leftToRight;

            // add the current level to the result
            result.push_back(level);
        }

        return result;
    }
};