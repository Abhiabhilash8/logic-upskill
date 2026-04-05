// Last updated: 4/5/2026, 11:43:23 AM
class Solution {
public:
    int bestClosingTime(string c) {
        vector<int>ptn(c.size()+1,0),pty(c.size()+1,0);
        ptn[0]=0;
        int countn=0,county=0;
        for(int i=0;i<c.size();i++){
            if(c[i]=='N') countn++;
            ptn[i+1]=countn;
        }
        pty[c.size()]=0;
        for(int i=c.size()-1;i>=0;i--){
            if(c[i]=='Y') county++;

            pty[i]=county;
        }

        int ans=0;
        for(int i=0;i<=c.size();i++) ans=(pty[ans]+ptn[ans]>pty[i]+ptn[i])? i:ans; 

        return ans;
    }
};