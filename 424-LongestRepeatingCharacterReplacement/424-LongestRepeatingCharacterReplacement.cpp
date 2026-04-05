// Last updated: 4/5/2026, 11:45:58 AM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,n=s.size(),mf=0,ans=0;
        int arr[26]={0};
        while(r<n){
            arr[s[r]-'A']++;
            mf=max(mf,arr[s[r]-'A']);
            if(r-l+1-mf<=k){
                ans=max(ans,r-l+1);
            }
            else{
                arr[s[l]-'A']--;
                l++;
            }
            r++;
        }

        return ans;
    }
};