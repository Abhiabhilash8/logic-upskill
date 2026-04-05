// Last updated: 4/5/2026, 11:44:46 AM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        int ktemp=k,ans=0;
        int ptr1=0,ptr2=0;
        while(ptr2<nums.size()){
            if(k==0&&nums[ptr2]==0){
                ptr1++;
                if(ptr2<ptr1) ptr2=ptr1;
                continue;
            }
            else if(nums[ptr2]==1){
            ans=max(ans,ptr2-ptr1+1);
                ptr2++;
            }
            else{
                if(ktemp>0){
                    ktemp--;
                    nums[ptr2++]=-1;
                    ans=max(ans,ptr2-ptr1);
                }
                else{
                    while(ptr1<nums.size()&&nums[ptr1]!=-1){
                        ptr1++;
                    }
                   if(ptr1<nums.size()) nums[ptr1++]=0;
                    ktemp++;
                }
            }
        
        }
        return ans;
    }
};