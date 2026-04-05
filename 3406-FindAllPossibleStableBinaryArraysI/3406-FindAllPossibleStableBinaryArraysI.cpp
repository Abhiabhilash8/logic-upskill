// Last updated: 4/5/2026, 11:43:04 AM
class Solution {
public:
    int numberOfStableArrays(int z, int o, int lt) {
        int M=1000000007;
        int dp[o+1][z+1][2];
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=dp[0][0][1]=1;
        for(int i=0;i<=o;i++){
            for(int j=0;j<=z;j++){
                if(i==0 && j==0) continue;
                int res=0;
                // prev ending at 0
                for(int k=1;k<=min(lt,i);k++){
                    res=(res+dp[i-k][j][0])%M;
                }
                dp[i][j][1]=res;

                res=0;
                // prev ending at 1
                for(int k=1;k<=min(lt,j);k++){
                    res=(res+dp[i][j-k][1])%M;
                }

                dp[i][j][0]=res;

            }
        }

        return (dp[o][z][1]+dp[o][z][0])%M;
    }
};