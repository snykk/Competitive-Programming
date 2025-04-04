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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);
    }

private:
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(nullptr); // Empty tree
            return result;
        }

        // Iterate through all possible roots
        for (int i = start; i <= end; ++i) {
            // Generate all left and right subtrees
            vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end);

            // Combine left and right subtrees with the current root
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i, left, right);
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
