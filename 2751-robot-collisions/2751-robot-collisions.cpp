class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hp, string dir) {
        int n=pos.size();
        vector<int>id(n);
        for(int i=0;i<n;i++) id[i]=i;
        sort(id.begin(),id.end(),[&](int a,int b){
            return pos[a]<pos[b];
        });
        stack<int>st;
        for(int i=0;i<n;i++){
            int f=0,cur=id[i];
            while(st.size() && dir[cur] == 'L' && dir[st.top()] == 'R'){
                int past=st.top();
                st.pop();
                if(hp[cur]>hp[past]){
                    hp[past]=-1;
                    hp[cur]-=1;
                }else if(hp[cur]<hp[past]){
                    st.push(past);
                    hp[past]-=1;
                    hp[cur]=-1;
                    f=1;
                    break;
                }
                else{
                    hp[past]=-1;
                    hp[cur]=-1;
                    f=1;
                    break;
                }
            }
            if(!f) st.push(cur);


        }

        vector<int>a;
        for(int i=0;i<n;i++){
            if(hp[i]>0) a.push_back(hp[i]);
        }
        return a;
    }
};