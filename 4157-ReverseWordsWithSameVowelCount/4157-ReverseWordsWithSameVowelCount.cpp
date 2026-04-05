// Last updated: 4/5/2026, 11:41:25 AM
class Solution {
public:
    int vow(vector<int>& hash){
        return hash['a'-'a']+hash['e'-'a']+hash['i'-'a']+hash['o'-'a']+hash['u'-'a'];
    }
    string reverseWords(string s) {
        stringstream ss(s);
        string vec;
        int count=0;
        int f=0;
        string word;
        while(ss >> word){
            vector<int>hash(27,0);
            for(int i=0;i<word.size();i++) hash[word[i]-'a']++;
            if(f==0){
                count=vow(hash);
                f=1;
                vec+=word;
            }
            else if(vow(hash)==count){
                string temp=word;
                reverse(temp.begin(),temp.end());
                vec+=" "+temp;
            }else{
                vec+=" "+word;
            }
        }

        

        return vec;
    }
};