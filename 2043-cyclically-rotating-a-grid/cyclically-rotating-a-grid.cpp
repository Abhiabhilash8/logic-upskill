class Solution {
public:

    void thirgu(vector<vector<int>>&g,int r1, int r2, int c1, int c2, int k){
        vector<int>temp;
        for(int i = r1; i<r2 ; i++) temp.push_back(g[i][c1]);
        for(int j = c1; j<c2; j++) temp.push_back(g[r2][j]);
        for(int i = r2; i>r1; i--) temp.push_back(g[i][c2]);
        for(int j = c2; j>c1; j--) temp.push_back(g[r1][j]);
        int n = temp.size();
        k %= n;
        int p = (n - k)%n;

        for(int i = r1; i<r2 ; i++) {g[i][c1] = temp[p]; p = (p+1)%n;}
        for(int j = c1; j<c2; j++) {g[r2][j] = temp[p]; p = (p+1)%n;}
        for(int i = r2; i>r1; i--){ g[i][c2] = temp[p]; p = (p+1)%n;}
        for(int j = c2; j>c1; j--) {g[r1][j] = temp[p]; p = (p+1)%n;}
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& g, int k) {
        int n = g.size() , m = g[0].size();
        int r1=0,r2=n-1,c1=0,c2=m-1;
        while(r1<r2 && c1<c2){
            thirgu(g,r1,r2,c1,c2,k);
            r1++,r2--,c1++,c2--;
        }

        return g;
    }
};