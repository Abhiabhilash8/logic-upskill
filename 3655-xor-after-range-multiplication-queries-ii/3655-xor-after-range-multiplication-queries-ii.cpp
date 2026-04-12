class Solution {
public:

 int M = 1e9+7;
    //Binary Exponentiation for Fermat's Little Theorem - > Pow(v ,M-2)
    long long power(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half   = power(a, b/2);
        long long result = (half * half) % M;

        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int blocksize=ceil(sqrt(n));
        unordered_map<int,vector<vector<int>>>mpp;
        for(auto &q: queries){
            int l=q[0],r=q[1],k=q[2],v=q[3];
            if(k>=blocksize){
                for(int i=l;i<=r;i+=k)
                nums[i]=(1ll * (nums[i]%M) * (v%M))%M;
            }else mpp[k].push_back(q);
        }

        for(auto& [k,allqueries]: mpp){
            vector<long long>dif(n,1);
            for(auto &q: allqueries){
                int l=q[0],r=q[1],k=q[2],v=q[3];
                dif[l]=(dif[l]*v)%M;
                int steps=(r-l)/k;
                int next=l+(steps+1)*k;
                if(next < n) dif[next] = (dif[next] * power(v, M-2)) % M;
            }

            for(int i=0;i<n;i++){
                if(i-k>=0) dif[i]=(dif[i] * dif[i-k])%M;
            }

            for(int i=0;i<n;i++) nums[i]=(1ll * nums[i] * dif[i])%M;

        }

        int res=0;
        for(int i=0;i<n;i++) res^=nums[i];

        return res;
    }
};