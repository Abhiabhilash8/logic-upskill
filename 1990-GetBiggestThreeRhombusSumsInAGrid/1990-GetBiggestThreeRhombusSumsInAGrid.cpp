// Last updated: 4/5/2026, 11:43:47 AM
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        // gand faad debug

        int n=grid.size(),m=grid[0].size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) pq.push(grid[i][j]);
        for(int l=2;l<=25;l++){


            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    // cout<<"i:"<<i<<" j:"<<j<<" l:"<<l<<endl;
                    int c=0,ni=i,nj=j,cs=0;

                    // s1
                    for(int k=0;k<l && ni<n && nj<m;k++){
                        cs+=grid[ni++][nj++];
                        c++;
                    }
                    // cout<<" cs:"<<cs<<" c:"<<c<<" side: 1"<<endl;
                    if(c!=l) continue;
                    c=0,ni--,nj--;
                    cs-=grid[ni][nj];


                    // s2
                    for(int k=0;k<l && ni<n && nj>=0;k++){
                        cs+=grid[ni++][nj--];
                        c++;
                    }
                    // cout<<" cs:"<<cs<<" c:"<<c<<" side: 2"<<endl;
                    if(c!=l) continue;
                    c=0,ni--,nj++;
                    cs-=grid[ni][nj];


                    // s3
                    for(int k=0;k<l && ni>=0 && nj>=0;k++){
                        cs+=grid[ni--][nj--];
                        c++;
                    }
                    // cout<<" cs:"<<cs<<" c:"<<c<<" side: 3"<<endl;
                    if(c!=l) continue;
                    c=0,ni++,nj++;
                    cs-=grid[ni][nj];


                    // s4
                    for(int k=0;k<l && ni>=0 && nj<m; k++){
                        cs+=grid[ni--][nj++];
                        c++;
                    }
                    // cout<<" cs:"<<cs<<" c:"<<c<<" side: 4"<<endl;
                    if(c!=l) continue;
                    c=0,ni++,nj--;
                    cs-=grid[ni][nj];

                    pq.push(cs);

                }
            }


    }
            vector<int>ans;
            while(pq.size() && ans.size()<3){
                if(!ans.size() || pq.top()!=ans[ans.size()-1]) ans.push_back(pq.top());
                pq.pop();
            }

            return ans;

        }
};