// Last updated: 4/5/2026, 11:46:48 AM
class Solution {
public:

    void f(int i,int n,int k,int csum,vector<int>temp,vector<vector<int>>&ans){
        if(i==10||csum>n){
            if(csum==n&&temp.size()==k){
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(i);
        f(i+1,n,k,csum+i,temp,ans);
        temp.pop_back();
        f(i+1,n,k,csum,temp,ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;

        f(1,n,k,0,temp,ans);

        return ans;
        
    }
};