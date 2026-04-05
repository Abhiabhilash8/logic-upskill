// Last updated: 4/5/2026, 11:48:46 AM
class Solution {
public:

    void help(vector<vector<int>>&ans,vector<int>temp,vector<int>&candidates,int target,int csum,int i){
        if(csum==target){
            vector<int>temp2(temp.begin(),temp.end());
            // sort(temp2.begin(),temp2.end());
            ans.push_back(temp2);
            return;
        }
        else if(csum>target||i>=candidates.size()){
            return;
        }
        else{
            csum+=candidates[i];
            temp.push_back(candidates[i]);
            help(ans,temp,candidates,target,csum,i+1);
            temp.pop_back();
            csum-=candidates[i];
            while(i+1<candidates.size()&&candidates[i+1]==candidates[i]) i++;
            help(ans,temp,candidates,target,csum,i+1);
        }
    }


    // void unq(vector<vector<int>>&ans){
    //     vector<vector<int>>fans;
    //     for(int i=1;i<ans.size();i++){
    //         int f=0;
    //         for(int j=0;j<ans[i].size();j++){
    //             if(ans[i][j]!=ans[i-1][j]){
    //                 f=1;
    //                 break;
    //             } 
                
    //         }
    //         if(f==1){
    //                 fans.push_back(ans[i-1]);
    //             }
    //     }
    //     if(fans.size()!=0) fans.push_back(ans[ans.size()-1]);
    //     ans=fans;
    // }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        help(ans,temp,candidates,target,0,0);
        return ans;
    }
};