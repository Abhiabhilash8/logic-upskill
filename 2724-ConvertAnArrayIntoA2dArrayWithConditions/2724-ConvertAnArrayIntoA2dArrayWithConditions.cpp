// Last updated: 4/5/2026, 11:43:18 AM
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int>temp(201,0);
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]++;
        }

        int c=nums.size();
        while(1){
            if(c==0) break;
            vector<int>row;
            for(int i=0;i<=200;i++){
                if(temp[i]){
                    row.push_back(i);
                    temp[i]--;
                    c--;
                }
            }

            ans.push_back(row);

        }

        return ans;
    }
};