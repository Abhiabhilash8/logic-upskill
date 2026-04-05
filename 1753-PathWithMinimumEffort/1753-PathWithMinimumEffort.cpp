// Last updated: 4/5/2026, 11:44:05 AM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>mine(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        mine[0][0]=0;
        q.push({INT_MAX,{0,0}});
        while(q.size()){
            int row=q.front().second.first,col=q.front().second.second;
            int wt=q.front().first;
            q.pop();

            for(int x=-1;x<=1;x++){
                if(x==0) continue;
                int i=x+row,j=col;
                int tht;
               if(i>=0 && i<m && j>=0 && j<n) tht=max(abs(heights[i][j]-heights[row][col]),mine[row][col]);
                if(i>=0 && i<m && j>=0 && j<n && tht<mine[i][j]){
                        mine[i][j]=tht;
                        q.push({tht,{i,j}});
                    }
            }
            for(int x=-1;x<=1;x++){
                if(x==0) continue;
                int i=row,j=x+col;
                int tht;
               if(i>=0 && i<m && j>=0 && j<n) tht=max(abs(heights[i][j]-heights[row][col]),mine[row][col]);
                if(i>=0 && i<m && j>=0 && j<n && tht<mine[i][j]){
                        mine[i][j]=tht;
                        q.push({tht,{i,j}});
                    }
            }


        }

        return mine[m-1][n-1];
    }
};