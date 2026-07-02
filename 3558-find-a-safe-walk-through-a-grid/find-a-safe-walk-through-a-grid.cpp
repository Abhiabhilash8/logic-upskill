class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>>dist(n , vector<int>(m , INT_MAX));
        priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
        >pq;
        pq.push({grid[0][0] , 0 , 0});
        int di[] = {0 , 0 , -1 , 1};
        int dj[] = {-1 , 1 , 0 , 0};
        while(pq.size()){
            vector<int>v = pq.top();
            pq.pop();
            if(v[0] > dist[v[1]][v[2]]) continue;

            for(int k = 0; k<4; k++){
                int ni = di[k] + v[1], nj = dj[k] + v[2];
                if(ni < 0 || ni >= n || nj < 0 || nj >= m || dist[ni][nj] <= v[0] + grid[ni][nj]) continue;

                dist[ni][nj] = v[0] + grid[ni][nj];
                pq.push({dist[ni][nj] , ni , nj});
            }
        }

        return dist[n-1][m-1] < health;
    }
};