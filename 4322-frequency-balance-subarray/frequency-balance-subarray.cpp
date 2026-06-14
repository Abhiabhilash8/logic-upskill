class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i<n; i++){
            map<int,int>mpp;
            vector<int>f(1001,0);
            int mfe = nums[i];
            for(int j=i;j<n; j++){
                mpp[nums[j]]++;
                f[mpp[nums[j]] - 1]--;

                f[mpp[nums[j]]]++;

                int cursize = j-i+1;
                if(mpp[mfe] < mpp[nums[j]]) mfe = nums[j];

                int hf = mpp[mfe];
                int no_of_hfe = f[hf];
                int unq_e = mpp.size();
                int half_hf = hf /2;
                int normal_ele = unq_e - no_of_hfe;
                if(normal_ele == 0 && f[hf] == 1) ans = max(ans , cursize);
                if(!(hf & 1) && normal_ele && f[half_hf] == normal_ele){
                    ans = max(ans , cursize);
                }

            }
        }

        return ans;
    }
};