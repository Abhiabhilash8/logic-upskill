class Solution {
public:

    unordered_set<string>ans;
    int reqlen;
    void f(int i , string &s , string &k , int cs){
        if(cs < 0) return;
        if(s.size() == i){
            if(cs == 0 && k.size() == reqlen) ans.insert(k);
            return;
        }
        if(s[i] != '(' && s[i] != ')'){
            k += s[i];
            f(i + 1 , s , k , cs);
            k.pop_back();
            return;
        }


        k += s[i];
        f(i + 1 , s , k , cs + (s[i] == '(' ? 1: -1));
        k.pop_back();
        f(i + 1 , s , k , cs);
    }

    vector<string> removeInvalidParentheses(string s) {
        int n = s.size() , cs = 0 , rem = 0;
        for(auto c: s){
            if(c != ')' && c != '(') continue;
            if(c == ')') cs--;
            else cs ++;
            if(cs < 0){
                rem++;
                cs = 0;
            }
        }

        rem += cs;
        cout<<rem;

        reqlen = n - rem;
        string k = "";
        f(0 , s , k , 0);

        return vector<string>(ans.begin() , ans.end());
    }
};