/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head; // Edge case: empty list, single node, or no rotation
        }

        // Find the length of the list
        ListNode* current = head;
        int n = 1;
        while (current->next) {
            current = current->next;
            n++;
        }

        // Connect the tail to the head to form a circular list
        current->next = head;

        // Find the new tail position
        k = k % n;  // Reduce k modulo n
        if (k == 0) {
            current->next = nullptr; // Break the circle
            return head;             // No rotation needed
        }
        
        int newTailPos = n - k;
        current = head;
        for (int i = 1; i < newTailPos; ++i) {
            current = current->next;
        }

        // Break the circle and set the new head
        ListNode* newHead = current->next;
        current->next = nullptr;

        return newHead;
    }
};
