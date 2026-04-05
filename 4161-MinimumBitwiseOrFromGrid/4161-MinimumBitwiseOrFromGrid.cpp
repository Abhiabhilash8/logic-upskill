// Last updated: 4/5/2026, 11:41:22 AM
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int track=0,ans=0,pick=0;

        for(int bit=31;bit>=0;bit--){
            pick=(track|(1<<bit));

            bool foundz=true;
            for(int i=0;i<n;i++){
                bool fornow=false;
                for(int j=0;j<m;j++){
                   if((grid[i][j] & pick) == 0){
                        fornow=true;
                        break;
                   } 
                }
                if(!fornow){
                    foundz=false;
                    break;
                }
            }

            if(foundz){
                track=pick;
            }else{
                ans|=(1<<bit);
            }
        }


        return ans;
    }
};