class Solution {
public:
    void built(vector<int>&p,vector<bool>&isp,int N){
        isp[0]=isp[1]=0;
        for(int i=2;i*i<=N;i++){
            if(isp[i]){
                for(int j=i*i;j<=N;j+=i){
                    isp[j]=0;
                }
            }
        }

        for(int i=2;i<=N;i++){
            if(isp[i]) p.push_back(i);
        }
    }
    int minOperations(vector<int>& nums) {
        vector<int>p;
        int N=1e5+4;
        vector<bool>isp(N,1);
        built(p,isp,N-1);
        int a=0;

        for(int i=0;i<nums.size();i++){
            if((i&1) && isp[nums[i]]){
                if(nums[i]==2) a+=2;
                else a++;
            }
            else if(!(i&1)){
                int ind=lower_bound(p.begin(),p.end(),nums[i])-p.begin();
                a+=(p[ind]-nums[i]);
            }
        }

        return a;
    }
};