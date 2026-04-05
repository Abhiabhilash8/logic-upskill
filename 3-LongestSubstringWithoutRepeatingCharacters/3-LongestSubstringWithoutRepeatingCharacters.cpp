// Last updated: 4/5/2026, 11:49:19 AM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        map<char,int>mpp;
        int ptr1=0,ptr2=0,ans=1;
        while(ptr2<s.size()){
            mpp[s[ptr2]]++;
            
            while(mpp[s[ptr2]] != 1){
                mpp[s[ptr1]]--;
                ptr1++;
            }
             
                ans=max(ans,ptr2-ptr1+1);
                ptr2++;
            
        }
        return ans;
    }
};