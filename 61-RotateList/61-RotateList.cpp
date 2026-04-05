// Last updated: 4/5/2026, 11:48:29 AM
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

    int length(ListNode* head){
        int l=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            l++;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0) return head;
        ListNode* p1=head;
        ListNode* p2=head;
        k=k%length(head);
        if(k==0) return head;
        for(int i=0;i<k;i++) p2=p2->next;
        while(p2->next){
            p1=p1->next;
            p2=p2->next;
        }

        ListNode* temp=p1->next;
        p2->next=head;
        p1->next=NULL;
        return temp;
        
    }
};