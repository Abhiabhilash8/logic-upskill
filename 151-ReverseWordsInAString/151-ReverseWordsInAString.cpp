// Last updated: 4/5/2026, 11:47:22 AM
class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int wstart=s.size()-1,wend=s.size()-1;
        while(wstart>=0){
            while(wstart>=0&&s[wstart]==' ') wstart--;
            if(wstart==-1)  break;
            
            wend=wstart;

            while(wend>=0&&wend>=0&&s[wend]!=' ') wend--;

            wend++;
            ans+={s.begin()+wend,s.begin()+wstart+1};
            wstart=wend-1;
            ans+=' ';
        }
        while(!ans.empty()&&ans.back()==' ') ans.pop_back();
        return ans;

    }
};