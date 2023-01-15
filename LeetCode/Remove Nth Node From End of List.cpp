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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0,c=1;
        ListNode* h=new ListNode(0);
        ListNode* temp=head;
        ListNode* temp1=h;
        h->next=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        temp=head;

        while(c!=len-n+1)
        {
            temp1=temp;
            temp=temp->next;
            c++;
        }

        temp1->next=temp->next;
        delete temp;
        return h->next;
    }
};