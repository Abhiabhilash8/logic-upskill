// Last updated: 4/5/2026, 11:47:03 AM
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
    ListNode* removeElements(ListNode* head, int valu) {
        if(head==NULL) return NULL;
        while(head!=NULL&&head->val==valu){
           
            head=head->next;
           
        }
        struct ListNode *temp=head;
        while(temp!=NULL&&temp->next!=NULL){
            if(temp->next->val==valu){
              
                temp->next=temp->next->next;
              
            }
            else
                temp=temp->next;
        }
       return head; 
    }
};