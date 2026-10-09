class Solution {
public:
    int minInsertions(string s) {
        int c = 0 , ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') c += 1;
            else if(i + 1 == s.size() || s[i + 1] != ')'){
                ans++;
                c--;
            }
            else{
                c--;
                i++;
            }

            if( c < 0 ){
                c = 0;
                ans++;
            }
        }

        return ans + 2 * c;
    }
};