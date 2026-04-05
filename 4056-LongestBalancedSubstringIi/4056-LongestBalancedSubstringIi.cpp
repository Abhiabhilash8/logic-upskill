// Last updated: 4/5/2026, 11:41:58 AM
class Solution {
public:

    int sin(string &s){
        int su=1,ms=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) su++;
            else su=1;
            ms=max(su,ms);
        }
        return ms;
    }

    int duo(string &s,char a,char b){
        map<int,int>mpp;
        mpp[0]=-1;
        int cs=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=a && s[i]!=b){
                mpp.clear();
                cs=0;
            }
            else if(s[i]==a) cs++;
            else cs--;

            if(mpp.find(cs)!=mpp.end()){
                ans=max(ans,i-mpp[cs]);
            }else mpp[cs]=i;
        }

        return ans;
    }


    int tri(string &s){
        int n=s.size(),ans=0;
        vector<int>c(3,0);
        map<pair<int,int>,int>mpp;
        mpp[{0,0}]=-1;
        pair<int,int>tg;
        for(int i=0;i<n;i++){
            c[s[i]-'a']++;
            tg={c[1]-c[0],c[2]-c[0]};
            if(mpp.find(tg)!=mpp.end()){
                ans=max(ans,i-mpp[tg]);
            }else mpp[tg]=i;
        }

        return ans;
    }

    int longestBalanced(string s) {
        return max({duo(s,'a','b'),duo(s,'b','c'),duo(s,'a','c'),sin(s),tri(s)});
    }
};