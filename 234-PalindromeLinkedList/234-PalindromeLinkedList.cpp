// Last updated: 4/5/2026, 11:46:37 AM
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

    ListNode* reverse(ListNode* head){
        if(!head||head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* next=cur->next;
        while(cur){
            cur->next=prev;
            prev=cur;
            cur=next;
            if(next) next=next->next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow&&fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=reverse(slow->next);
        ListNode* ptr1=head;
        ListNode* ptr2=newhead;
        while(ptr2){
            if(ptr1->val!=ptr2->val) return false;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return true;

    }
};