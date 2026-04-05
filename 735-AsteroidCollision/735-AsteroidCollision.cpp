// Last updated: 4/5/2026, 11:45:23 AM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int>st;
        bool f=false;
        for(int i=0;i<as.size();i++){
            f=false;
            if(!st.size()){
                st.push(as[i]);
                continue;
            }
            if(!(st.top()>0 && as[i]<0)) {st.push(as[i]);continue;}
           while(st.size() && st.top()>0&&as[i]<0){
            if(abs(as[i])>st.top()) st.pop();
            else if(abs(as[i])==st.top()){
                st.pop();
                f=true;
                break;
            }
            else {
                f=true;
                break;
                }
           }

           if(!f) st.push(as[i]);

        }

        vector<int>ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};