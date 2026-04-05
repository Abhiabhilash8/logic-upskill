// Last updated: 4/5/2026, 11:41:29 AM
class Solution {
public:

    long long f(vector<int>&nums,int st){
        long long a=0;
        for(int i=st;i<nums.size()-1;i+=2){
            long long k = max(nums[i-1],nums[i+1]);
            if(k<nums[i]) continue;
            else a+=(k-nums[i]+1);
        }

        return a;
    }
    long long hehe(vector<int>&nums){
        int n=nums.size();

        vector<long long>pre;
        long long s=0;
        pre.push_back(s);
        for(int i=1;i<n-1;i+=2){
            long long k = max(nums[i-1],nums[i+1]);
            if(k>=nums[i]) s+=(k-nums[i]+1);
            pre.push_back(s);
            // cout<<s<<endl;
        }

        vector<long long>post;
        s=0;
        post.push_back(s);
        for(int i=n-2;i>=1;i-=2){
            long long k = max(nums[i-1],nums[i+1]);
            if(k>=nums[i]) s+=(k-nums[i]+1);
            post.push_back(s);
        }
        reverse(post.begin(),post.end());


        long long ans=1e18;
        for(int i=0;i<pre.size();i++){
            // cout<<pre[i]<<" "<<post[i]<<endl;
            ans=min(ans,pre[i]+post[i]);
        }

        return ans;
        
    }
    
    long long minIncrease(vector<int>& nums) {
        if(nums.size()&1) return f(nums,1);
        else {
            return hehe(nums);
        }
    }
};