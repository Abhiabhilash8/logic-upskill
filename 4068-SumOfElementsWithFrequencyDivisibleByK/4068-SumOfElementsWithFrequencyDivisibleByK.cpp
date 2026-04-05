// Last updated: 4/5/2026, 11:41:53 AM
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++) mpp[nums[i]]++;

        int sum=0;
        for(auto &it: mpp){
            int key=it.first;
            int value=it.second;
            if(value%k==0) sum+=((value/k) * key*k);
        }

        return sum;
        
    }
};