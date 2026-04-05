// Last updated: 4/5/2026, 11:40:41 AM
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int>s;
        for(int i=1;i<=n;i++){
            if(i>=n || i*i>=n ||i*i*i>=n) break;
            s.push_back (i*i*i);
        }

        map<int,int>mpp;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                mpp[s[i]+s[j]]++;
            }
        }

        vector<int>ans;
        for(auto it:mpp){
            if(it.first>n) break;
            else if(it.second>=2)ans.push_back(it.first);
        }

        return ans;
    }
};