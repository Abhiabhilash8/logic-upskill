class Solution {
public:

    void f(vector<long long>&ans , vector<int>&nums){
        map<long long , pair<long long , long long>>mpp;
        for(int i = 0;i<nums.size() ; i++){
            long long f = mpp[nums[i]].first,s = mpp[nums[i]].second;
            ans[i] += f*i - s;

            mpp[nums[i]].first++;
            mpp[nums[i]].second+=i;
        }
    }

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long>ans(n,0);
        f(ans , nums);
        reverse(ans.begin() , ans.end());
        vector<int>duck = nums;
        reverse(duck.begin() , duck.end());
        f(ans , duck);

        reverse(ans.begin() , ans.end());

        return ans;

    }
};