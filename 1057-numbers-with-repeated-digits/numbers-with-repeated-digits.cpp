class Solution {
public:

    int dp[11][2][2][1024][2];

    int ddp(int idx , bool tight , bool lz , int mask , bool  rep , string &sn){
        if(idx == sn.size()) return rep;
        if(dp[idx][tight][lz][mask][rep] != -1) return dp[idx][tight][lz][mask][rep];
        int ub = tight? sn[idx] - '0' : 9;
        int c = 0;
        for(int i = 0; i<=ub ; i++){
            bool lead_z = lz && i == 0;
            bool is_rep = rep || (!lead_z && (mask & (1 << i)));
            int n_mask = lead_z ? mask : mask | (1 << i);
            
            c += ddp(idx + 1 , tight && i == ub , lz && i == 0 , n_mask , is_rep , sn);
        }

        return dp[idx][tight][lz][mask][rep] = c;
    }

    int numDupDigitsAtMostN(int n) {
        string sn = to_string(n);
        memset(dp , -1 , sizeof(dp));
        return ddp(0 , true , true , 0 , false , sn);
    }
};