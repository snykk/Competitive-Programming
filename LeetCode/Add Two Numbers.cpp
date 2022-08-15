/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ctx = 0;
        ListNode* result = nullptr;
        ListNode* current = nullptr;
        
        while (l1 != nullptr || l2 != nullptr || ctx != 0) {
            if (l1 != nullptr) {
                ctx += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                ctx += l2->val;
                l2 = l2->next;
            }
            
            auto dummy = new ListNode(ctx % 10);
            ctx = ctx > 9 ? 1 : 0;
            
            if (result != nullptr) {
                current->next = dummy;
                current = current->next;
             
            } else {
                result = dummy;
                current = result;
            }
        }
        
        return result;
    }
};