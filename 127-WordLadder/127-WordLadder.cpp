// Last updated: 4/5/2026, 11:47:34 AM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordlist) {
        unordered_set<string>st(wordlist.begin(),wordlist.end());
        queue<pair<string,int>>q;
        st.erase(beginWord);
        int steps=0;
        q.push({beginWord,steps});
        while(q.size()){
            string word=q.front().first;
            steps=q.front().second;
            if(word==endWord) return steps+1;
            q.pop();
            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(int j='a';j<='z';j++){
                    word[i]=j;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=ch;
            }

        }

        return 0;

    }
};