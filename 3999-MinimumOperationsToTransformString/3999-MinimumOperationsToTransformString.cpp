// Last updated: 4/5/2026, 11:42:14 AM
class Solution {
public:
    int minOperations(string s) {
        char minchar='z';
        int f=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='a'&&s[i]<=minchar){
                f=1;
                minchar=s[i];
            }
        }
        int ans=26-(minchar-'a');
        if(f==0) return 0;
        return ans;
    }
};