// Last updated: 4/5/2026, 11:49:10 AM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int f=0;
        if(strs.size()==1)  return strs[0];
        int n=strs.size(),j=0,i,leastlength=INT_MAX;
        for(int k=0;k<strs.size();k++){
            if(leastlength>strs[k].size())  leastlength=strs[k].size();
        }
        for(i=1;j<leastlength;i++){
            if(i%n==0)  j++;
            if(strs[i%n][j]!=strs[(i-1)%n][j])    break;
            if(i==leastlength)  f=1;
        }
        if(j==0&&f==0)    return "";
        return strs[0].substr(0,j);
    }
};