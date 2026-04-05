// Last updated: 4/5/2026, 11:46:03 AM
class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0,f=0;
        int arr[59]={0};
        for(int i=0;i<s.size();i++){
            arr[s[i]-'A']++;
        }
        for(int i=0;i<59;i++){
            
            if(arr[i]%2==1){
                 f=1;
                 ans+=arr[i]-1;
            }
            else ans+=arr[i];
            
        }
        if(f==1) ans+=1;
        return ans;
    }
};