// Last updated: 4/5/2026, 11:49:20 AM
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
    ListNode* insert(int x,struct ListNode* tail){
        struct ListNode* temp=new ListNode(x);
        temp->next=NULL;
        if(tail!=NULL) tail->next=temp;
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum1=0,i=0,x=0;

        
        struct ListNode* temp1=l1;
        struct ListNode* temp2=l2;
        struct ListNode* head;
        struct ListNode* tail;
        x=temp1->val+temp2->val;
        temp1=temp1->next;
        temp2=temp2->next;
        head=insert(x%10,NULL);
        tail=head;

        while(temp1!=NULL&&temp2!=NULL){
          x=x/10+temp1->val+temp2->val;
          temp1=temp1->next;
          temp2=temp2->next;
          tail=insert(x%10,tail);
        }
        while(temp1!=NULL){
            x=x/10+temp1->val;
            temp1=temp1->next;
            tail=insert(x%10,tail);
        }
        while(temp2!=NULL){
            x=x/10+temp2->val;
            temp2=temp2->next;
            tail=insert(x%10,tail);
        }
        if(x/10>0){
            tail=insert(x/10,tail);
        }
        return head;
    }
};