// Last updated: 4/5/2026, 11:47:16 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=0,n=0,dif;
        struct ListNode *tempa=headA;
        struct ListNode *tempb=headB;
        while(tempa!=NULL){
            m++;
            tempa=tempa->next;
        }
         while(tempb!=NULL){
            n++;
            tempb=tempb->next;
        }
        tempa=headA;
        tempb=headB;
        dif=m-n;
        
            if(dif>0){
                while(dif!=0){
                    tempa=tempa->next;
                    dif--;
                }
            }
            else{
                while(dif!=0){
                    tempb=tempb->next;
                    dif++;
                }
            }
            while(tempa!=NULL&&tempb!=NULL){
                if(tempa==tempb)
                    return tempa;
                    else{
                        tempa=tempa->next;
                        tempb=tempb->next;
                    }
            }
            return NULL;
    }
};