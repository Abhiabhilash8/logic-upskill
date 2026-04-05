// Last updated: 4/5/2026, 11:48:03 AM
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
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next) return head;
     

        ListNode* cur=head;
        if(head->val>=x){
            while(cur->next&&cur->next->val>=x){
                cur=cur->next;
            }
            if(!cur->next) return head;

            ListNode* temp=head;
            head=cur->next;
            cur->next=cur->next->next;
            head->next=temp;
        }
        cur=head;
        
            while(cur->next&&cur->next->val<x){
                cur=cur->next;

            }
        

        ListNode* mid = cur;
        // cur=head;
        ListNode* temp;
        while(cur->next){
            if(cur->next->val<x&&cur!=mid){
                temp=cur->next;
                cur->next=temp->next;
                temp->next=mid->next;
                mid->next=temp;
                mid=mid->next;
                
            }
            else{
                cur=cur->next;
            }
        }

        return head;

    }
};