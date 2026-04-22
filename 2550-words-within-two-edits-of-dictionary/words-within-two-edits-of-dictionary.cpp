class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dic) {
        vector<string>a;
        for(auto &s: queries){
            for(auto &d: dic){
                int c=0;
                for(int i=0;i<d.size() && c<3;i++){
                    if(s[i]!=d[i]) c++;
                }
                if(c<=2){
                    a.push_back(s);
                    break;
                }
            }
        }

        return a;
    }
};