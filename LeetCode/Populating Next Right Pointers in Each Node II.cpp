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

        Node* curr = root; // start with the root node
        while (curr) {
            Node dummyHead(0); // dummy node to track the next level
            Node* tail = &dummyHead; // tail pointer for the next level

            // traverse the current level
            while (curr) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next; // move to the next node in the current level
            }

            // move to the next level
            curr = dummyHead.next;
        }

        return root;
    }
};