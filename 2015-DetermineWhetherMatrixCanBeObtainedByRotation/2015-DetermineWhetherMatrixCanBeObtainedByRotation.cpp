// Last updated: 4/5/2026, 11:43:46 AM
class Solution {
public:

void hehe(vector<vector<int>>& mat){
    int n=mat.size();
    // rotate logic
    // transpose and flip cols
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j) swap(mat[i][j],mat[j][i]);
        }
    }
    for(int j=0;j<n/2;j++){
        for(int i=0;i<n;i++) swap(mat[i][j],mat[i][n-j-1]);
    }

    
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int r=0;r<4;r++){

            int f=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(target[i][j]!=mat[i][j]){
                        f=1;
                        break;
                    }
                }
                if(f) break;
            }
            if(!f) return true;
            hehe(mat);
        }

        return false;
    }
};