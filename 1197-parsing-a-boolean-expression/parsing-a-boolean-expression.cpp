class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(auto c: expression){
            if(c == ')'){
                vector<bool>v;
                while(1){
                    if(st.top() == '('){
                        st.pop();
                        break;
                    }else if(st.top() == ','){
                        st.pop();
                    }
                    else{
                        v.push_back(st.top() == 't'?1:0);
                        st.pop();
                    }
                }
                char op = st.top();
                bool  res = v[0];
                st.pop();
                if(op == '|') for(int i = 1; i<v.size(); i++) res |= v[i]; 
                else if(op == '&') for(int i = 1; i<v.size(); i++) res &= v[i];
                else  res = !res;

                st.push(res?'t':'f');
            }
            else st.push(c);
        }

        return st.top() == 't'?1:0;
    }
};