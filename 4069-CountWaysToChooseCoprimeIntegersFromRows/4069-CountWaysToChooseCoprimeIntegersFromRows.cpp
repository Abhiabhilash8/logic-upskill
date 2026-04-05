// Last updated: 4/5/2026, 11:41:52 AM
class Solution {
public:

    int f(int i,int j,int result,vector<vector<vector<int>>>&dp,vector<vector<int>>&mat,int mod){
        if(i==mat.size()) return (result==1);
        if(dp[i][j][result]!=-1) return dp[i][j][result];

        long long sum=0;
        for(int ind=0;ind<mat[0].size();ind++){
            sum=(sum+f(i+1,ind,__gcd(result,mat[i][ind]),dp,mat,mod))%mod;
        }

        return dp[i][j][result]=sum;
    }
    
    int countCoprime(vector<vector<int>>& mat) {
        // if(mat.size()==1) return 0;
        int temp=0;
        if(mat.size()==1){
            for(int j=0;j<mat[0].size();j++){
                if(mat[0][j]==1) temp++;
            }

            return temp;
        }
    
        int maxv=0;
        int mod=1e9+7;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++) maxv=max(maxv,mat[i][j]);
        }
        vector<vector<vector<int>>> dp(mat.size(), vector<vector<int>>(mat[0].size(), vector<int>(maxv + 1, -1)));
        long long sum=0;
        
        for(int ind=0;ind<mat[0].size();ind++){
            sum=(sum+f(1,ind,mat[0][ind],dp,mat,mod))%(mod);
        }
        

        return sum;
    }
};