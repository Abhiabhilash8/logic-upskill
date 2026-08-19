class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int c = 0;
        map<int,vector<int>>mpp;
        for(auto &it: rs) mpp[it[0]].push_back(it[1]);
        for(auto &it: mpp){
            vector<int>v(11 , 0);
            for(auto x: it.second) v[x]++;
            
            if(!v[2] && !v[3] && !v[4] && !v[5] &&
               !v[6] && !v[7] && !v[8] && !v[9])
                c += 2;

            else if((!v[2] && !v[3] && !v[4] && !v[5]) ||
                    (!v[4] && !v[5] && !v[6] && !v[7]) ||
                    (!v[6] && !v[7] && !v[8] && !v[9]))
                c += 1;
        }

        c += (n - mpp.size()) * 2;
        return c;
    }
};