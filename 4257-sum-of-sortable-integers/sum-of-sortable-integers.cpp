class Solution {
public:
typedef long long ll;
#define pb push_back

// ---------------------------------
    void getf(long long n,vector<ll>&f){
        int i=1;
        for(i=1;i*i<n;i++){
            if(n%i==0){
                f.pb(i);
                f.pb(n/i);
            }
        }

        if(i*i==n) f.pb(i);
    }


    bool c(int st,int end,vector<int>&nums,int &curmin,int &curmax){
        curmin=nums[st];
        curmax=nums[st];

        int d=0;
        for(int i=st+1;i<=end;i++){
            curmin=min(curmin,nums[i]);
            curmax=max(curmax,nums[i]);;
            if(nums[i]<nums[i-1]) d++;
        }

        return d==0 || (d==1 && nums[st]>=nums[end]);
    }



    int sortableIntegers(vector<int>& nums) {
        vector<ll>fac;
        getf(nums.size(),fac);
        int n=nums.size(),ans=0;


        for(int j=0;j<fac.size();j++){
            int k=fac[j],f=0;
            int prevmax=-1,curmax,curmin;
            for(int i=0;i<n;i+=k){
                curmin=INT_MAX,curmax=INT_MIN;
                if(!c(i,i+k-1,nums,curmin,curmax) || curmin<prevmax) {
                    f=1;
                    break;
                }   
                prevmax=curmax;             
            }
            if(!f) ans+=k;
        }

        return ans;
    }
};