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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // create a hashmap to store the indices of elements in inorder
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        // start the recursive function to build the tree
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
    }

private:
    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd,
                     vector<int>& postorder, int postStart, int postEnd,
                     unordered_map<int, int>& inorderMap) {
                        
        // base case: if the range is invalid, return null
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        // the root is the last element in the current range of postorder
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // find the position of the root in inorder using the hashmap
        int rootIndex = inorderMap[rootVal];

        // calculate the size of the left subtree
        int leftTreeSize = rootIndex - inStart;

        // recursively build the left subtree
        root->left = helper(inorder, inStart, rootIndex - 1,
                            postorder, postStart, postStart + leftTreeSize - 1, inorderMap);

        // recursively build the right subtree
        root->right = helper(inorder, rootIndex + 1, inEnd,
                             postorder, postStart + leftTreeSize, postEnd - 1, inorderMap);

        return root;
    }
};