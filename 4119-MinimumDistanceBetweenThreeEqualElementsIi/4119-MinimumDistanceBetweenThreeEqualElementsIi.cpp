// Last updated: 4/5/2026, 11:41:35 AM
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>>vec(1e5+1);
        for(int i=0;i<nums.size();i++){
            vec[nums[i]].push_back(i);
        }

        // sort(vec.begin(),vec.end());
        int ans=INT_MAX;

        for(int i=0;i<vec.size();i++){
            if(vec[i].size()>=3){
                for(int j=2;j<vec[i].size();j++){
                    ans=min(ans,(abs(vec[i][j]-vec[i][j-1])+abs(vec[i][j]-vec[i][j-2])+abs(vec[i][j-1]-vec[i][j-2])));
                }
            }
        }


        if(ans==INT_MAX) return -1;
        return ans;
    }
};