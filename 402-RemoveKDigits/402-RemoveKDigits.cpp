// Last updated: 4/5/2026, 11:46:05 AM
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(int i=0;i<num.size();i++){
            while(st.size() && k && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // cout<<"here is k "<<k<<" ";
        while(st.size() && k--) st.pop();
        if(st.size()) cout<<st.top()-'0'<<"\n";

        string ans="";

        while(st.size()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0') i++;

        string fans=ans.substr(i,ans.size());

        if(fans=="") return "0";
        else return fans;


    }
};