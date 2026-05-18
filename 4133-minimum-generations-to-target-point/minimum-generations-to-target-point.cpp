class Solution {
public:
    int minGenerations(vector<vector<int>>& p, vector<int>& tg) {
        int ans = 0;
        set<vector<int>>st;
        while(1){
            int z = 0;
            for(auto v: p){
                if(v[0] == tg[0] && v[1] == tg[1] && v[2] == tg[2]) return ans;
            }

            vector<vector<int>>np = p;


            for(int i=0; i<p.size(); i++){
                for(int j = i; j<p.size(); j++){
                    int a = (p[i][0] + p[j][0])/2 , b = (p[i][1] + p[j][1])/2 , c = (p[i][2] + p[j][2])/2;
                    if(st.find({a,b,c}) ==st.end()) {np.push_back({ a , b , c });st.insert({a,b,c});};
                }
            }

            if(p.size() == np.size()) return -1;


            ans++;
            p = np;

        }

        return -1;
    }
};