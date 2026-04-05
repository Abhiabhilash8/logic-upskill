// Last updated: 4/5/2026, 11:47:31 AM
class Solution {
public:

    bool ispal(int i,int j,string s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }

        return true;
    }

    void pt(int i,vector<string>temp,vector<vector<string>>&ans,string s){
        if(i==s.size()){
            ans.push_back(temp);
        }
        string t="";

        for(int j=i;j<s.size();j++){
            t+=s[j];
            if(ispal(i,j,s)){
                temp.push_back(t);
                pt(j+1,temp,ans,s);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        pt(0,temp,ans,s);
        return ans;
    }
};