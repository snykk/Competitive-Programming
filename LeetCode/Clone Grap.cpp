/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> cloned; // Map to store cloned nodes

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; // Handle empty graph

        // If node is already cloned, return it
        if (cloned.find(node) != cloned.end()) 
            return cloned[node];

        // Clone the node
        Node* newNode = new Node(node->val);
        cloned[node] = newNode;

        // Clone neighbors using DFS
        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return newNode;
    }
};