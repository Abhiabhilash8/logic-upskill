// Last updated: 4/5/2026, 11:42:31 AM
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int>mpp;
        for(int i=0;i<points.size();i++){
            mpp[points[i][1]]++;
        }
        vector<long long>vec;
        for(auto &it: mpp){
            int f=it.second;
            if(f>=2)
            vec.push_back(f);
        }
        if (vec.size() < 2) return 0;


        long long ans=0;
        int mod=1e9+7;
        vector<long long>postsum(vec.size(),0);
        long long s=0;



        for(int i=vec.size()-1;i>=0;i--){
            s+=((1ll*vec[i]*(vec[i]-1))/2)%mod;
            postsum[i]=s;
        }


        for(int i=0;i<vec.size()-1;i++){
            ans=(ans+(((1LL*vec[i]*(vec[i]-1))/2)*postsum[i+1])%mod)%mod;
        }

        return ans;

    }
};