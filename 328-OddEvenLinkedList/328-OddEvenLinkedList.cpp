// Last updated: 4/5/2026, 11:46:16 AM
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL||head->next->next==NULL) return head;
        ListNode* h2=head->next;
        ListNode* p1=head;
        ListNode* p2=h2;
        while(1){
            if(p1&&p1->next) p1->next=p1->next->next;
            if(p2&&p2->next) p2->next=p2->next->next;

            if(p1&&p1->next) p1=p1->next;
            if(p2) p2=p2->next;

            if(!p1->next&&!p2) break;
        }
        p1->next=h2;
        return head;


    }
};