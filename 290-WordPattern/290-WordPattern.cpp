// Last updated: 4/5/2026, 11:46:24 AM
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        map<int,string>mpp;
        map<string,int>mpp2;
        int j=0;
        for(int i=0;i<pattern.size();i++){
            string temp="";
            while(j<s.size()&&(s[j]!=' ')){
                temp+=s[j++];
            }
            if((j==s.size()&&i!=pattern.size()-1)||(j!=s.size()&&i==pattern.size()-1)) return false;
            j++;
            if((mpp.find(pattern[i])==mpp.end())&&(mpp2.find(temp)==mpp2.end())){
                mpp[pattern[i]]=temp;
                mpp2[temp]=pattern[i];
            }
            else {
                if(mpp.find(pattern[i])==mpp.end()&&mpp2.find(temp)!=mpp2.end()) return false;
                if(mpp.find(pattern[i])!=mpp.end()&&mpp2.find(temp)==mpp2.end()) return false;
                if(mpp[pattern[i]]!=temp||mpp2[temp]!=pattern[i]) return false;
            }
        }

        return true;
    }
};