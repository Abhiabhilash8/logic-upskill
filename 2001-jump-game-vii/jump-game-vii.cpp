class Solution {
public:
    bool canReach(string s, int minj, int maxj) {
        int n = s.size();
        vector<int>track(n+1,0);

        for(int i = 0; i<n; i++){
            if(i>0) track[i] += track[i-1];
            if(s[i] == '0' && (((i-maxj <= 0) && (i-minj>=0)) || ((i-minj >= 0) && (track[i-minj] > track[i-maxj-1])))){
                track[i]++;
                if(i==n-1) return true;
            }
        }


        return false;
    }
};