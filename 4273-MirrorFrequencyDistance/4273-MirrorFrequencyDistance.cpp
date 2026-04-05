// Last updated: 4/5/2026, 11:40:43 AM
class Solution {
public:
    int mirrorFrequency(string s) {
        map<char,int>mpp;
        for(auto c: s){ mpp[c]++;
        char m = (c >= 'a' && c <= 'z') ? ('z' - (c - 'a')) : ('9' - (c - '0'));
            mpp[m];
        }

        int ans=0;
        for(auto &it: mpp){
            // if(it.second==0) continue;
            ans+=abs(it.second-((it.first>='a' && it.first<='z')?mpp['z'-(it.first-'a')]:mpp['9'-(it.first-'0')]));
            int v=(it.first>='a' && it.first<='z')? mpp['z'-it.first]:mpp['9'-it.first];
        }

        return ans/2;
    }
};