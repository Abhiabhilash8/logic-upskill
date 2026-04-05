// Last updated: 4/5/2026, 11:43:35 AM
class Solution {
public:

    void rev(int ind,string  &word){
        int i=0;
        while(i<ind){
            swap(word[i++],word[ind--]);
        }
    }
    string reversePrefix(string word, char ch) {
        int i=0;
        while(i<word.size()&&word[i]!=ch) i++;
        if(i!=word.size()){
            rev(i,word);
        }
        return word;
    }
};