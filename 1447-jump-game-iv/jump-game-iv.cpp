class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>>mpp;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            mpp[arr[i]].push_back(i);
        }
        bool vis[n];
        memset(vis,false,sizeof(vis));
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        int ans = 0;
        while(q.size()){
            int k = q.size();
            while(k--){
                int cur = q.front();
                q.pop();
                if(cur == n-1) return ans;
                if(cur>0 && !vis[cur-1]){
                    q.push(cur-1);
                    vis[cur-1] = 1;
                }
                if(cur<n-1 && !vis[cur+1]){
                    q.push(cur+1);
                    vis[cur+1] = 1;
                }

                for(auto faah: mpp[arr[cur]]){
                    if(!vis[faah]){
                        q.push(faah);
                        vis[faah] = 1;
                    }
                }
                mpp[arr[cur]].clear();
            }

            ans++;
        }

        return ans;
    }
};