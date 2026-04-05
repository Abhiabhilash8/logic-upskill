// Last updated: 4/5/2026, 11:43:01 AM
class Solution {
public:
    string clearDigits(string s) {
        vector<char>result;
        int f=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>47&&s[i]<58){
                f++;
            }
            else if(f!=0){
                //result.push_back(s[i]);
                f--;
            }
            else
            result.push_back(s[i]);
            
        }
       reverse(result.begin(),result.end());
       string req(result.begin(),result.end());
        //char req[result.size()];
       /* for(int i=0;i<result.size();i++){
            req[i]=result[result.size()-i-1];
        }*/
        return req;
    }
};