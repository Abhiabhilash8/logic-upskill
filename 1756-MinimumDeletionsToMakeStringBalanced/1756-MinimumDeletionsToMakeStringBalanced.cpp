// Last updated: 4/5/2026, 11:44:03 AM
class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>prea(n,0),postb(n,0);
        int pa=0,pb=0;
        for(int i=0;i<n;i++){
            pa+=s[i]!='a',pb+=s[n-i-1]!='b';
            prea[i]=pa,postb[n-i-1]=pb;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++) ans=min(ans,prea[i]+postb[i]-1);
        return ans;
    }
};