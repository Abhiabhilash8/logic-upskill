// Last updated: 4/5/2026, 11:48:01 AM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1=m-1,ptr2=n-1,ptr3=m+n-1;
        while(ptr3!=-1){
            if(ptr1==-1){
                while(ptr2!=-1){
                    nums1[ptr3--]=nums2[ptr2--];
                }
                break;
            }
            else if(ptr2==-1){
                while(ptr1!=-1){
                    nums1[ptr3--]=nums1[ptr1--];
                }
                break;
            }
            else if(nums1[ptr1]>=nums2[ptr2]){
                nums1[ptr3--]=nums1[ptr1--];
               
            }
            else{
                nums1[ptr3--]=nums2[ptr2--];
            }
        }
        
        
        
            }
};