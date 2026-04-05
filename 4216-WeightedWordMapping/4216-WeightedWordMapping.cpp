// Last updated: 4/5/2026, 11:41:09 AM
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto s: words){
            int su=0;
            for(auto c: s){
                su+=weights[c-'a'];
            }
            ans+='z'-(su%26);
        }

        return ans;
    }
};