class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<int,pair<bool,bool>>mpp;
        for(int i = 0; i<word.size(); i++){
            if(word[i] <= 90) mpp[word[i] - 'A'].first = 1;
            else mpp[word[i] - 'a'].second = 1;
        }

        int c = 0;
        for(auto &it: mpp){
            c += it.second.first && it.second.second;
        }

        return c;
    }
};