// Last updated: 4/5/2026, 11:43:02 AM
class Solution {
public:
    int numberOfStableArrays(int z, int o, int lt) {
        int M=1000000007;
        int dp[z+1][o+1][2];
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=min(lt,o);i++){
            dp[0][i][1]=1;
        }
        for(int i=1;i<=min(lt,z);i++){
            dp[i][0][0]=1;
        }

        for(int i=1;i<=z;i++){
            for(int j=1;j<=o;j++){


                // prev ending at 1
                dp[i][j][1]=(dp[i][j-1][1]+dp[i][j-1][0])%M;
                if(j-1>=lt) dp[i][j][1]=(dp[i][j][1]-dp[i][j-lt-1][0] + M)%M;

                // prev ending at 0
                dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%M;
                if(i-1>=lt) dp[i][j][0]=(dp[i][j][0]-dp[i-lt-1][j][1] + M)%M;

                

            }
        }

        return (dp[z][o][1]+dp[z][o][0])%M;
    }
};