// Last updated: 4/5/2026, 11:48:12 AM
class Solution {
public:
    void help(vector<vector<int>>&ans,vector<int>&temp,int n,int k,int i){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        else if(i==n+1) return;
        else{
            temp.push_back(i);
            help(ans,temp,n,k,i+1);
            temp.pop_back();
            help(ans,temp,n,k,i+1);
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        help(ans,temp,n,k,1);
        return ans;
    }
};