class Solution {
public:

    void hamla(int i , int j , queue<pair<int,int>>&q , int n, int m , vector<vector<pair<int,int>>>&v , pair<int,int>&donga , int level){
        if(i<0 || i>=n || j<0 || j>=m || (v[i][j].first != -1 && (level>v[i][j].first || v[donga.first][donga.second].second<=v[i][j].second))) return ;

        v[i][j].first = level,v[i][j].second = v[donga.first][donga.second].second;
         q.push({i,j});
        // if(level == 2){cout<<i<<" "<<j<<endl;
        // cout<<"level: "<<v[i][j].first<<" color: "<<v[i][j].second<<endl;}
    }

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<pair<int,int>>>v(n,vector<pair<int,int>>(m,{-1 , -1}));
        // v stores level,color
        queue<pair<int,int>>q;
        for(auto &s: sources){
            v [s[0]] [s[1]] ={0,s[2]}; 
            q.push({s[0] , s[1]});
        }

        int level = 0;

        while(q.size()){
            int lol = q.size();
            level++;
            while(lol--){
                auto donga = q.front();
                q.pop();
                int dr[]={0,1,0,-1},dc[] = {1,0,-1,0};
                for(int i=0;i<4;i++) hamla(donga.first + dr[i] ,donga.second + dc[i] , q , n , m , v , donga , level);
            }
        }


        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = v[i][j].second;
            }
        }


        return ans;






    }
};