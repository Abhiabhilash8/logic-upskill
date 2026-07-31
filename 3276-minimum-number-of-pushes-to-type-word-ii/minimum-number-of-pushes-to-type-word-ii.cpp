class Solution {
public:
    int minimumPushes(string word) {
        vector<int>f(26 , 0);
        for(auto c: word) f[c - 'a']++;
        sort(word.begin() , word.end() , [&](char a , char b){
            if(f[a - 'a'] != f[b - 'a']) return f[a - 'a'] > f[b - 'a'];
            else return a < b;
        });
    
        vector<bool>vis(26 , false);
        int count = 0 , cost = 0 , ans = 0;
        for(int i = 0; i<word.size(); i++){
            if(vis[word[i] - 'a']) continue;
            if(!count) cost++;
            count = (count + 1)%8;
            ans += f[word[i] - 'a'] * cost;
            vis[word[i] - 'a'] = true;
        }

        return ans;

    }
};