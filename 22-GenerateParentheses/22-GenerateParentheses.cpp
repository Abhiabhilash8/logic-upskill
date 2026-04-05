// Last updated: 4/5/2026, 11:49:00 AM
class Solution {
public:
void f(int open,int close,int c,string temp,vector<string>&ans){
    if(open+close==0){ 
    ans.push_back(temp);
    return;
    }

    if(open<close){
        f(open,close-1,c-1,temp+")",ans);
    }
    if(open>0) f(open-1,close,c+1,temp+"(",ans);
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        f(n,n,0,temp,ans);

        return ans;
    }
};