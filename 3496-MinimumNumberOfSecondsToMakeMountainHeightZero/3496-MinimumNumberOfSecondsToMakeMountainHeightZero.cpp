// Last updated: 4/5/2026, 11:42:56 AM
class Solution {
public:

    bool c(long long t,vector<int>&v,long long h){
        for(int i=0;i<v.size();i++){
            long long ch=0,k=1;
            for(;ch+v[i]*k<=t;k++){
                ch+=v[i]*k;
                if(k>=h) return true;
            }
            h-=k-1;
        }

        return h<=0;
    }

    long long minNumberOfSeconds(int h, vector<int>& v) {
        long long l=0,r=1e18;

        while(r-l>1){
            long long m=l+(r-l)/2;
            if(c(m,v,h)) r=m;
            else l=m;
        }

        return r;
    }
};