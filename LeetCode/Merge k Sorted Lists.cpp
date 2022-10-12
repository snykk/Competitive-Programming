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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        }

        ListNode* temporary = new ListNode();
        priority_queue<pair<int,ListNode*>> myQueue;

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr) {
			//enter lisit values as -1*val to convert maxheap into minheap
            myQueue.push(make_pair((lists[i]->val)*(-1),lists[i])); 
            }
        }

        ListNode* temp = temporary;
        while(!myQueue.empty()) {
            ListNode* ln = (myQueue.top().second);
            myQueue.pop();

            if(ln->next != nullptr) {
				//push next pair of value and pointer.
                myQueue.push(make_pair(-1*((ln->next)->val),ln->next));
            }

            temp->next = ln;
            temp = temp->next;
            
        }

        return temporary->next;
    }
};