class Solution {
public:
    string decodeCiphertext(string et, int n) {
        vector<vector<char>>g(n,vector<char>(et.size()/n));
        int k=0,m=et.size()/n;;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                g[i][j]=et[k++];
            }
        }

        string ans="";
        for(int j=0;j<m;j++){
            int k=j;
            for(int i=0;i<n && k<m;i++,k++){
                ans+=g[i][k];
            }
        }

        int j=ans.size()-1;
        while(j>=0 && ans[j]==' ') j--;

        return string(ans.begin(),ans.begin()+j+1);
    }
};