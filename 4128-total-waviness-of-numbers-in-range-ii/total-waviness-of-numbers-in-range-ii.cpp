class Solution {
public:

    pair<long long, long long> dp[18][2][12][12];

    pair<long long , long long> ddp(int idx , bool tight , int ld , int sld , string &n){
        if(idx == n.size()) return {0,1};
        if (dp[idx][tight][ld + 1][sld + 1].first != -1) return dp[idx][tight][ld + 1][sld + 1];

        int ub = tight ? (n[idx] - '0') : 9;
        long long mk = 0,tw = 0;
        for(int i = 0; i <= ub; i++){
            int next_ld = (ld == -1 && i == 0)? -1 : i;
            int next_sld = (ld == -1 && i == 0)? -1 : ld;

            pair<long long , long long > ch = ddp(idx + 1 , tight && (i == ub) , next_ld , next_sld , n);
            long long is_wav = (ld != -1 && sld != -1) && (((ld > sld) && (ld > i)) || ((ld < sld) && (ld < i)));
            mk += ch.first + (is_wav * ch.second);
            tw += ch.second;
        }

        return dp[idx][tight][ld + 1][sld + 1] = {mk, tw};
    }

    long long f(long long n){
        string ns = to_string(n);
        memset(dp, -1, sizeof(dp));
        // i have idx , tight = false , ld,sd,ns,dp
        return ddp(0 , true , -1 , -1 , ns ).first;
    }

    long long totalWaviness(long long num1, long long num2) {
        return f(num2) - f(num1 - 1);
    }
};