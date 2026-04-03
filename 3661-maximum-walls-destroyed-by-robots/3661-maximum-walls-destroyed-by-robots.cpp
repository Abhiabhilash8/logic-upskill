class Solution {
public:

    int countwalls(int st,int end,vector<int>&walls){
        int l=lower_bound(walls.begin(),walls.end(),st) - walls.begin();
        int r=upper_bound(walls.begin(),walls.end(),end) - walls.begin();

        return r-l;
    }

    int solve(vector<pair<int,int>>&robotdist, vector<int>&walls,vector<pair<int,int>>&range,int i,int dir,vector<vector<int>>&dp){
        int n=robotdist.size();
        if(i==n) return 0;
        if(dp[i][dir]!=-1) return dp[i][dir];
        int leftstart=range[i].first,goleft,goright;
        if(dir==1){
            leftstart=max(leftstart,range[i-1].second+1);
        }
        goleft=countwalls(leftstart,robotdist[i].first,walls) + solve(robotdist,walls,range,i+1,0,dp);
        goright=countwalls(robotdist[i].first,range[i].second,walls) + solve(robotdist,walls,range,i+1,1,dp);

        return dp[i][dir] = max(goleft,goright);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size();
        vector<pair<int,int>>robotdist(n),range(n);
        vector<vector<int>>dp(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            robotdist[i]={robots[i],distance[i]};
        }
        sort(robotdist.begin(),robotdist.end());
        sort(walls.begin(),walls.end());
        for(int i=0;i<n;i++){
            int pos=robotdist[i].first;
            int d=robotdist[i].second;

            int leftlimit=(i==0)? 1:robotdist[i-1].first+1;
            int rightlimit=(i==n-1)? 1e9:robotdist[i+1].first-1;

            int l=max(pos-d,leftlimit);
            int r=min(pos+d,rightlimit);

            range[i]={l,r};
        }

        return solve(robotdist,walls,range,0,0,dp);
    }
};