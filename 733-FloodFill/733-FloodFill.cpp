// Last updated: 4/5/2026, 11:45:25 AM
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int same=image[sr][sc];
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(q.size()){
            int i=q.front().first;
            int j=q.front().second;
            image[i][j]=color;
            q.pop();
            vis[i][j]=1;
            if(i-1>=0 && image[i-1][j]==same && !vis[i-1][j]) q.push({i-1,j}); 
            if(j-1>=0 && image[i][j-1]==same && !vis[i][j-1]) q.push({i,j-1}); 
            if(i+1<image.size() && image[i+1][j]==same && !vis[i+1][j]) q.push({i+1,j}); 
            if(j+1<image[0].size() && image[i][j+1]==same && !vis[i][j+1]) q.push({i,j+1}); 
        }

        return image;
    }
};