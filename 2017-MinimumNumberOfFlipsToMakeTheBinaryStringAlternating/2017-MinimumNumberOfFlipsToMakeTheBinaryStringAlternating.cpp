// Last updated: 4/5/2026, 11:43:45 AM
class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s=s+s;
        char sz='0',so='1';
        int az=0,ao=0,i;
        for(i=0;i<n;i++){
            if(sz!=s[i]) az++;
            if(so!=s[i]) ao++;

            sz=sz=='1'?'0':'1';
            so=so=='1'?'0':'1';
        }
        int ans=min(az,ao);
        for(i;i<2*n;i++){
            if(sz!=s[i]) az++;
            if(so!=s[i]) ao++;
            if( (!(n&1) && sz!=s[i-n]) || ((n&1) && sz==s[i-n])) az--;
             if( (!(n&1) && so!=s[i-n]) || ((n&1) && so==s[i-n])) ao--;

            ans=min({ans,az,ao});
            sz=sz=='1'?'0':'1';
            so=so=='1'?'0':'1';
        }

        return ans;

    }
};