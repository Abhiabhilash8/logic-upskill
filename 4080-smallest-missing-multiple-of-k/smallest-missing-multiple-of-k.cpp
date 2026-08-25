class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int>vec(101,0);
        for(int i=0;i<nums.size();i++){
            vec[nums[i]]++;
        }
        for(int i=k;;i=i+k){
            if(i>=101||!vec[i]) return i; 
        }

        return k;
    }
};