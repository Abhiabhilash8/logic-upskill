// Last updated: 4/5/2026, 11:49:04 AM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int x=0,y=nums.size()-1;
        
        vector<vector<int>>res;
        if(nums.size()<4) return res;
        for(x=0;x<=nums.size()-4;x++){
            if(x>0&&nums[x]==nums[x-1]) continue;
            for(y=x+1;y<=nums.size()-3;y++){
                if(y>x+1&&nums[y]==nums[y-1]) continue;
               long long int csum;
                for(int i=y+1,j=nums.size()-1;i<j;){
                    csum=(long long)nums[x]+nums[y]+nums[i]+nums[j];
                    if(csum==target){
                        res.push_back({nums[x],nums[y],nums[i],nums[j]});
                        i++,j--;
                    while(i<j&&nums[i]==nums[i-1]) i++;
                    while(i<j&&nums[j]==nums[j+1]) j--;
                    }
                    else if(target<csum) j--;
                    else i++;    

                }
            }
        }    
        return res;
    }
};