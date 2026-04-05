// Last updated: 4/5/2026, 11:42:32 AM
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& gr, int k) {
        int dif=INT_MAX,n=gr.size(),m=gr[0].size();
        vector<vector<int>>ans;
        for(int i=0;i+k-1<n;i++){
            vector<int>t;
            ans.push_back(t);
            for(int j=0;j+k-1<m;j++){


                int cur=INT_MAX;
                for(int ii=i;ii<i+k;ii++){
                    for(int jj=j;jj<j+k;jj++){

                        for(int ic=ii;ic<i+k;ic++){
                            for(int jc=j;jc<j+k;jc++){
                                if(gr[ii][jj]==gr[ic][jc]) continue;

                                cur=min(cur,abs(gr[ii][jj]-gr[ic][jc]));
                            }
                        }

                    }
                }

                if(cur==INT_MAX) cur=0;
                ans[i].push_back(cur);


            }
        }


        return ans;
    }
};