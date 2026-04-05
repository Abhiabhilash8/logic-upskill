// Last updated: 4/5/2026, 11:47:28 AM
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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        do{
            if(fast->next==NULL||fast->next->next==NULL||slow->next==NULL) return false;
            else{
                slow=slow->next;
                fast=fast->next->next;
            }
        }while(slow!=fast);
        return true;
    }
};