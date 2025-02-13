#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Node for Doubly Linked List
struct Node {
    int key, value;
    Node *prev, *next;
    
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// Abstract Cache Class
class Cache {
protected:
    unordered_map<int, Node*> mp;
    int cp;
    Node *head, *tail; // Pointers for head & tail of doubly linked list

public:
    Cache(int capacity) {
        cp = capacity;
        head = tail = nullptr;
    }

    virtual void set(int, int) = 0;
    virtual int get(int) = 0;
};

// Derived LRUCache Class
class LRUCache : public Cache {
public:
    LRUCache(int capacity) : Cache(capacity) {}

    // Move a node to the front (Most Recently Used)
    void moveToFront(Node* node) {
        if (node == head) return; // Already at front

        // Remove node from current position
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        
        if (node == tail) tail = node->prev; // If tail is removed, update tail
        
        // Move to front
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;

        // If only one node, set tail to head
        if (!tail) tail = head;
    }

    // Insert a new key-value pair
    void set(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // If key exists, update value and move to front
            mp[key]->value = value;
            moveToFront(mp[key]);
        } else {
            // If cache is full, remove the least recently used item (tail)
            if (mp.size() == cp) {
                mp.erase(tail->key);
                tail = tail->prev;
                if (tail) tail->next = nullptr;
            }

            // Create new node and insert at front
            Node* newNode = new Node(key, value);
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            
            // If cache was empty, update tail
            if (!tail) tail = head;

            // Add to hash map
            mp[key] = newNode;
        }
    }

    // Retrieve value associated with a key
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1; // Key not found

        // Move accessed node to front
        moveToFront(mp[key]);
        return mp[key]->value;
    }
};

// Main function
int main() {
    int n, capacity;
    cin >> n >> capacity;

    LRUCache lru(capacity);

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "set") {
            int key, value;
            cin >> key >> value;
            lru.set(key, value);
        } else if (command == "get") {
            int key;
            cin >> key;
            cout << lru.get(key) << endl;
        }
    }

    return 0;
}
