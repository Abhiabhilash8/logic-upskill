class Solution {
public:

    int f(int st , int end , unordered_map<int,int>&mpp){
        if(st == end - 1) return 1;
        if(mpp[st] == end) return 2 * f(st + 1 , end - 1 , mpp);
        int ans = 0;
        int cur = st;
        while(cur < end){
            ans += f(cur , mpp[cur] , mpp);
            cur = mpp[cur] + 1;
        }

        return ans;
    }
    
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<int>st;
        unordered_map<int,int>mpp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(i);
            else{
                mpp[st.top()] = i;
                st.pop();
            }
        }

        return f(0 , s.size() - 1 , mpp);
    }
};