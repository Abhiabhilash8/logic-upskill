class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int s = nums[0];
        vector<bool>vis(55 , false);
        for(int i = 0; i<nums.size(); i++) vis[nums[i]] = true;
        for(int i =1; i<nums.size(); i++){
            vis[nums[i]] = 1;
            if(nums[i] == nums[i-1] + 1){
                s += nums[i];
            }else break;
        }
        

        for(int i = s; i<=54; i++){
            if(!vis[i]) return i;
        }
        return s;

        
    }
};