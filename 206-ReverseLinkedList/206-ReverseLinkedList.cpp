// Last updated: 4/5/2026, 11:46:58 AM
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

ListNode* help(ListNode* add,ListNode* root){
    if(root==NULL) return add;
    ListNode* temp=help(root,root->next);
    root->next=add;
    return temp;
}
    ListNode* reverseList(ListNode* head) {
       ListNode* temp= help(NULL,head);
        return temp;
    }
};