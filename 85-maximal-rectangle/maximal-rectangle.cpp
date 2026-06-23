class Solution {
public:

    int f(vector<int>&ht){
        int n = ht.size();
        stack<int>st;
        vector<int>ls(n) , rs(n);
        for(int i = 0; i<n; i++){
            while(!st.empty() && ht[i] <= ht[st.top()]) st.pop();
            ls[i] = st.empty()? 0:st.top() + 1;
            st.push(i);
        }

        while(st.size()) st.pop();
        for(int i = n-1; i>=0; i--){

            while(!st.empty() && ht[i] <= ht[st.top()]) st.pop();
            rs[i] = (st.empty()? n-1:st.top() - 1);
            if(st.size()) cout<<st.top()<<endl;
            st.push(i);
        }

        int a = 0;
        for(int i = 0; i<n; i++) a = max(a , ht[i] * (rs[i] - ls[i] + 1));

        return a;


    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        int ans = 0;
        vector<int>ht(m,0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1') ht[j]++;
                else ht[j] = 0;
            }
            ans = max(ans , f(ht));
        }

        return ans;
        


    }
};