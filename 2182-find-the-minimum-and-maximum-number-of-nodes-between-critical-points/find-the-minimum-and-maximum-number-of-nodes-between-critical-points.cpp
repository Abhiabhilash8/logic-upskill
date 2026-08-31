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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1 , -1};
        if(!head -> next) return ans;
        int prec = 0 , fc = 0;
        int c = 1;
        ListNode* prev = head;
        head = head -> next;
        if(!head -> next) return ans;
        ans[0] = INT_MAX;
        while(head -> next){
            c++;

            if(head -> val > prev -> val && head -> val > head -> next -> val
               || head -> val < prev -> val && head -> val < head -> next -> val){
                if(!fc) {
                    fc = c;
                    prec = c;
                }
                else{
                    ans[0] = min(ans[0] , c - prec);
                    ans[1] = c - fc;
                    prec = c;
                }
            }

            prev = head;
            head = head -> next;
        }
        if(ans[1] == -1) ans[0] = -1;

        return ans;
    }
};