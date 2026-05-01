class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int prev=0,s=0,cur=0;
        for(int i = 0;i<nums.size();i++){
            s+=nums[i];
            prev += i*nums[i];
        }
        int mk = prev;
        
        for(int i=0;i<nums.size();i++){
            cur = prev - s + nums.size()*nums[i];
            prev = cur;
            mk = max(mk , cur);
        }

        return mk;

    }
};