// Last updated: 4/5/2026, 11:44:37 AM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        vector<vector<int>>dist(grid.size(),vector<int>(grid.size(),1e8));
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        queue<pair<int,pair<int,int>>>pq;

        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(pq.size()){
            int row=pq.front().second.first;
            int col=pq.front().second.second;
            int curdist=pq.front().first;
            pq.pop();

            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    int i=row+x,j=col+y;
                    if(i>=0 && i<n && j>=0 && j<n && grid[i][j]==0 && curdist+1<dist[i][j]){
                        dist[i][j]=curdist+1;
                        pq.push({curdist+1,{i,j}});
                    }
                }
            }
        }

        if(dist[n-1][n-1]==1e8) return -1;
        else return dist[n-1][n-1]+1;

    }
};