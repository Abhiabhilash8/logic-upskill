// Last updated: 4/5/2026, 11:44:31 AM
class Solution {
public:

bool  check(vector<vector<int>>& mat,int s,int th){
    int n=mat.size(),m=mat[0].size();
    long long cs=0;


    for(int i=0;i+s<=n;i++){
        cs=0;
        for(int ti=i;ti<i+s;ti++) for(int tj=0;tj<s;tj++) cs+=mat[ti][tj];
        if(cs<=th) return true;


        for(int j=1;j+s<=m;j++){
            for(int k=i;k<i+s;k++) cs=(cs-mat[k][j-1]+mat[k][j+s-1]);
            if(cs<=th) return true;
        }
        

    }

    return false;
}

    int maxSideLength(vector<vector<int>>& mat, int th) {
        int n=mat.size(),m=mat[0].size();
        int l=0,r=min(m,n)+1;

        while(r-l>1){
            long long mid=r+(l-r)/2;
            if(check(mat,mid,th)) l=mid;
            else r=mid;
        }

        return l;
    }
};