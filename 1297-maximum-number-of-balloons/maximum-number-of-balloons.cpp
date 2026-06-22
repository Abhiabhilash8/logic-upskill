class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>f(26 , 0);
        for(int i = 0; i<text.size(); i++) f[text[i] - 'a']++;
        int mi = INT_MAX;

        string s = "balon";
        for(auto c: s){
            if(c == 'o' || c == 'l') mi = min(mi  , f[c - 'a']/2);
            else mi = min(mi , f[c - 'a']);
        }

        return mi;
    }
};