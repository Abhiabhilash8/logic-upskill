class Solution {
public:
vector<vector<int>> c(string word){
    int n=word.size();
    vector<vector<int>>lcp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        if(word[n-1]==word[i]){
            lcp[n-1][i]=lcp[i][n-1]=1;
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            lcp[i][j]=(word[i]==word[j])? 1+lcp[i+1][j+1]:0;
        }
    }

    return lcp;
}
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string word(n,'$');

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(lcp[i][j]){
                    word[i]=word[j];
                    break;
                }
            }
            

            if(word[i]=='$'){
                vector<bool>fb(26,0);
                for(int j=0;j<i;j++){
                    if(!lcp[i][j]) fb[word[j]-'a']=1;
                }
                for(int j=0;j<26;j++){
                    if(!fb[j]){
                        word[i]=j+'a';
                        break;
                    }
                }
            }

            if(word[i]=='$') return "";
        }

        return c(word)==lcp ? word:"";
    }
};