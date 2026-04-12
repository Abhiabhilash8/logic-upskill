class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>t(n+1,0);

        for(auto &sh: shifts){
            int l=sh[0],r=sh[1],d=sh[2];
            if(d){
                t[l]++;
                t[r+1]--;
            }else{
                t[l]--;
                t[r+1]++;
            }
        }
        for(int i=1;i<n;i++) t[i]+=t[i-1];
        for(int i=0;i<n;i++){
            s[i]=(s[i]-'a' + t[i]%26 + 26)%26 +'a';
        }

        return s;
    }

};