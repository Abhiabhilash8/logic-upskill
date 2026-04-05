// Last updated: 4/5/2026, 11:47:27 AM
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(slow){
        slow=slow->next;
        }
        else return NULL;
        if(fast->next){
         fast=fast->next->next;
        }
        else return NULL;
        while(slow&&fast&&fast->next){
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
            else{
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        return NULL;

    }
};