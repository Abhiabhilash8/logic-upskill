// Last updated: 4/5/2026, 11:43:32 AM
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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        if(!head->next->next){
            head->next=NULL;
            return head;
        }
        ListNode* slow=NULL;
        ListNode* fast=head;
        while(fast&&fast->next&&fast->next->next){
            if(!slow) slow=head;
            else
            slow=slow->next;
            fast=fast->next->next;
        }
        if(!slow) slow=head;
        if(fast->next) slow=slow->next;
        slow->next=slow->next->next;
        return head;
    }
};