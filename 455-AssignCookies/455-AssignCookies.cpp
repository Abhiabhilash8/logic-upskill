// Last updated: 4/5/2026, 11:45:54 AM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int p1=0,p2=0,c=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(p1<g.size()&&p2<s.size()){
            if(s[p2]>=g[p1]){
                c++;
                p2++,p1++;
            }
            else{
                p2++;
            }
        }

        return c;
    }
};