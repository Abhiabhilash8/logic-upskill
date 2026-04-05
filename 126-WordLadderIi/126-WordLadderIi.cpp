// Last updated: 4/5/2026, 11:47:35 AM
class Solution {
public:
void dfs(string lw,int steps,map<string,int>&mpp,vector<string>temp,vector<vector<string>>&ans){
    cout<<"here with lw: "<<lw<<" steps: "<<steps<<" \n";
    if(steps==1){
        reverse(temp.begin(),temp.end());
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<lw.size();i++){
        char ch=lw[i];
        for(int j='a';j<='z';j++){
            lw[i]=j;
            if(mpp.find(lw)!=mpp.end() && mpp[lw]==steps-1){
                temp.push_back(lw);
                dfs(lw,steps-1,mpp,temp,ans);
                temp.pop_back();
            }
        }
        lw[i]=ch;
    }
}
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
        
        int n=wl.size();
        set<string>st(wl.begin(),wl.end());
        if(st.find(ew)==st.end()) return {};
        vector<vector<string>>ans;
        queue<pair<string,int>>q;
        map<string,int>mpp;
        q.push({bw,1});
        st.insert(ew);
        mpp[bw]=1;
        st.erase(bw);
        int steps,f=0;
        while(q.size()){
            string word=q.front().first;
            steps=q.front().second;
            q.pop();

            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(int j='a';j<='z';j++){
                    word[i]=j;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                        mpp[word]=steps+1;
                    }
                    if(word==ew) f=1;

                }
                word[i]=ch;
            }
            if(f) break;
        }
        // for(auto it: mpp){
        //     cout<<it.first<<" "<<it.second<<"\n";
        // }
         vector<string>temp;
         temp.push_back(ew);
         dfs(ew,mpp[ew],mpp,temp,ans);

        return ans;
    }
};