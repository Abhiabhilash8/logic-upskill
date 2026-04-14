class Solution {
public:
    typedef long long ll;
    ll dp[105][10005];
    ll solve(int ri,int fi,vector<int>&robot,vector<int>&pos){
        if(ri>=robot.size()) return 0;

        if(fi>=pos.size()) return 1e15;

        if(dp[ri][fi]!=-1) return dp[ri][fi];

        ll take = abs(robot[ri]-pos[fi]) + solve( ri+1 , fi+1 , robot,pos);
        ll skip = solve(ri,fi+1,robot,pos);

        return dp[ri][fi] = min(take,skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        memset(dp,-1,sizeof(dp));
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>f;
        for(int i=0;i<factory.size();i++){
            for(int k=0;k<factory[i][1];k++) f.push_back(factory[i][0]);
        }

        return solve(0,0,robot,f);
    }
};