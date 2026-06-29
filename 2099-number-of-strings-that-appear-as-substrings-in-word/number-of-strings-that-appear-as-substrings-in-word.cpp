class Solution {
public:
struct  Trie{
    Trie* child[26];
    int ends;

    Trie(){
        memset(child , NULL , sizeof(child));
        ends = 0;
    }
};
    int numOfStrings(vector<string>& patterns, string word) {
        Trie* root = new Trie();
        for(auto &w: patterns){
            Trie* cur = root;
            for(auto c: w){
                if(!cur->child[c - 'a']) cur->child[c - 'a'] = new Trie();
                cur = cur -> child[c - 'a'];
            }
            cur -> ends++;
        }
        int ans = 0;

        for(int i = 0; i<word.size(); i++){
            Trie* cur = root;
            for(int j = i; j<word.size(); j++){
                if(!cur->child[word[j] - 'a']) break;
                cur = cur->child[word[j] - 'a'];
                ans += cur -> ends;
                cur -> ends = 0;
            }
        }

        return ans;
    }
};