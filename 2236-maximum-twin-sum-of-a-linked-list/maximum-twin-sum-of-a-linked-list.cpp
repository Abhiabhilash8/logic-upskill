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
    ListNode* rhead;
    void f(ListNode* head , ListNode* prev){
        if(!(head -> next)){
            rhead = head;
            head -> next = prev;
            return;
        }
        f(head -> next , head);
        head -> next = prev;
    }
    int pairSum(ListNode* head) {
        int m = 0;
        int c = 0;
        ListNode* t = head;
        while(t){t = t->next,c++;}
        t = head;
        int count = 0;
        c /= 2;
        while(count < c){count++ , t = t->next;}
        f(t , NULL);
        t = rhead;

        while(t){
            m = max(m , t->val + head -> val);
            t = t -> next;
            head = head -> next;
        }
        return m;
    }
};