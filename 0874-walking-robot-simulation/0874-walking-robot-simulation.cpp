class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& obstacles) {
        set<pair<int,int>>st;
        for(auto ob: obstacles){
            st.insert({ob[0],ob[1]});
        }
        int mk=0;

        vector<int>ac(2,0);
        vector<pair<int,int>>all={{0,1} , {1,0} , {0,-1} , {-1,0} };
        pair<int,int>d=all[0];
        int p=0;

        for(int i=0;i<cmd.size();i++){
            if(cmd[i]==-2){
                p=(p+3)%4;
                d=all[p];
            }else if(cmd[i]==-1){
                p=(p+1)%4;
                d=all[p];
            }else{
                while(cmd[i]--){
                    ac[0]+=d.first,ac[1]+=d.second;
                    if(st.find({ac[0],ac[1]})!=st.end()){
                        ac[0]-=d.first,ac[1]-=d.second;
                        break;
                    }
                    mk=max(mk,ac[0]*ac[0] + ac[1]*ac[1]);
                }
            }
            mk=max(mk,ac[0]*ac[0] + ac[1]*ac[1]);

        }

        return mk;
    }
};