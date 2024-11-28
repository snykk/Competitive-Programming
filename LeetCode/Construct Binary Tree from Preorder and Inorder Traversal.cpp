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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // create a hashmap to store the indices of elements in inorder
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        // start the recursive function to build the tree
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }

private:
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd,
                     vector<int>& inorder, int inStart, int inEnd,
                     unordered_map<int, int>& inorderMap) {
        
        // base case: if the range is invalid, return null
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // the root is the first element in the current range of preorder
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // find the position of the root in inorder using the hashmap
        int rootIndex = inorderMap[rootVal];

        // calculate the size of the left subtree
        int leftTreeSize = rootIndex - inStart;

        // recursively build the left subtree
        root->left = helper(preorder, preStart + 1, preStart + leftTreeSize,
                            inorder, inStart, rootIndex - 1, inorderMap);

        // recursively build the right subtree
        root->right = helper(preorder, preStart + leftTreeSize + 1, preEnd,
                             inorder, rootIndex + 1, inEnd, inorderMap);

        return root;
    }
};
