class Solution {
public:
    string processStr(string s) {
        string r;
        for(auto c: s){
            if(c == '*' && r.size()) r.pop_back();
            else if(c == '#') r += r;
            else if(c == '%') reverse(r.begin() , r.end());
            else if(c != '*') r += c;
        }

        return r;
    }
};