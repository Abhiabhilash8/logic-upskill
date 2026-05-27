class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<int,int>>f(26,{-1,1});
        // first occ of capital lett ind,-1 invalid,>=2 valid small lett before, 1 no valid small lett
        int c = 0;
        for(int i = word.size()-1; i>=0; i--){
            if(word[i] <= 'Z'){
                f[word[i] - 65].first = i;
            }
        } 

        for(int i = 0; i<word.size(); i++){
            if(word[i] >= 'a'){
                if(i > f[word[i] - 32 - 'A'].first || f[word[i] - 32 - 'A'].second == -1){
                    f[word[i] - 32 - 'A'].second = -1;
                    continue;
                }
                else f[word[i] - 32 - 'A'].second++;

            }
        }

        for(int i = 0; i<26; i++) c += f[i].second > 1;

        return c;
    }
};