/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        // start with the leftmost node of the current level
        Node* leftmost = root;

        // traverse levels
        while (leftmost->left) {
            // traverse nodes in the current level
            Node* head = leftmost;
            while (head) {
                // connect left child to right child
                head->left->next = head->right;

                // connect right child to the next node's left child
                if (head->next) {
                    head->right->next = head->next->left;
                }

                // move to the next node in the current level
                head = head->next;
            }

            // nove to the next level
            leftmost = leftmost->left;
        }

        return root;
    }
};
