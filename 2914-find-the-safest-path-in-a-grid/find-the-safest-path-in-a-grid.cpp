class Solution {
public:
    bool check(vector<vector<int>>&dist , int th){
        int n = dist.size();
        vector<vector<bool>>vis(n , vector<bool>(n , false));
        queue<pair<int,int>>q;
        q.push({0 , 0});
        vis[0][0] = 1;
        if(dist[0][0] < th) return false;

        int di[] = {0 , 0 , -1 , 1};
        int dj[] = {-1 , 1 , 0 , 0};
        while(q.size()){
            int i = q.front().first , j = q.front().second;
            q.pop();
            if((i == n-1) && (j == n-1)) return true;
            for(int k = 0; k<4; k++){
                int ni = di[k] + i, nj = dj[k] + j;

                if(ni <0 || ni >= n || nj < 0 || nj >= n || vis[ni][nj] || dist[ni][nj] < th) continue;
                vis[ni][nj] = 1;
                q.push({ni , nj});
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n , vector<int>(n , -1));
        queue<pair<int,int>>q;

        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                if( grid[i][j] ){ q.push({i , j});dist[i][j] = 0;}

        int di[] = {0 , 0 , -1 , 1};
        int dj[] = {-1 , 1 , 0 , 0};
        int level = 0;
        while(q.size()){
            int size = q.size();
            while(size--){
                int i = q.front().first , j = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++){
                    int ni = di[k] + i, nj = dj[k] + j;
                    if(ni <0 || ni >= n || nj < 0 || nj >= n || dist[ni][nj] != -1) continue;
                    dist[ni][nj] = level + 1;
                    q.push({ni , nj});
                }
            }
            level++;
        }
        

        int l = 0,r=801;
        while( r - l > 1){

            int m = l + (r - l) / 2;

            if( check(dist , m)) l = m;
            else r = m;
        }

        return l;

    }
};