/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; // Edge case: Empty list

        unordered_map<Node*, Node*> nodeMap; // Maps original nodes to their copies

        // Create copies of nodes and store them in the map
        Node* current = head;
        while (current) {
            nodeMap[current] = new Node(current->val); // Create new node
            current = current->next;
        }

        // Assigm next and random pointers
        current = head;
        while (current) {
            nodeMap[current]->next = nodeMap[current->next];     // Copy next pointer
            nodeMap[current]->random = nodeMap[current->random]; // Copy random pointer
            current = current->next;
        }

        return nodeMap[head]; // Return deep copy of head
    }
};
