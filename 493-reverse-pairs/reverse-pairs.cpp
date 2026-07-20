class Solution {
public:
    // typedef long long ll;
    int ans = 0;

    void mixer(vector<int>&nums , int st , int m , int end){
        vector<int>v;
        int i = st , j = m + 1;

        while(i<=m && j<=end){
            if(nums[i] < nums[j]) v.push_back(nums[i++]);
            else v.push_back(nums[j++]);
        }
        while(i<=m) v.push_back(nums[i++]);
        while(j<=end) v.push_back(nums[j++]);
        int ptr = 0;
        for(int i = st; i<=end; i++){
            nums[i] = v[ptr++];
        }
    }

    // mer function returns the sorted part, we find the possible pairs, again return the sorted merged part
    void mer(int st , int end , vector<int>&nums){
        cout<<ans<<endl;
        if(st >= end) return;
        int m = (st + end)/2;
        mer(st , m , nums);
        mer(m+1 , end , nums);

        for(int i = m+1; i<=end; i++){
            int ind = upper_bound(nums.begin() + st , nums.begin() + m + 1 , 2ll * nums[i]) - nums.begin();
            ans += (m - ind + 1);
        }
        // cout<<st<<" "<<end<<" ans: "<<ans<<endl;

        mixer(nums , st , m , end);
    }

    int reversePairs(vector<int>& nums) {
        mer(0,nums.size()-1,nums);

        return ans;
    }
};