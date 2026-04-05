// Last updated: 4/5/2026, 11:49:03 AM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        int i;
        ListNode* ptr1=head;
        ListNode* ptr2=head;
        for(i=1;ptr2->next!=NULL;i++){
            if(i>n){
                ptr1=ptr1->next;
            }
            ptr2=ptr2->next;
        }
        if(i<=n) return ptr1->next;
        ptr1->next=ptr1->next->next;
        return head;

    }
};