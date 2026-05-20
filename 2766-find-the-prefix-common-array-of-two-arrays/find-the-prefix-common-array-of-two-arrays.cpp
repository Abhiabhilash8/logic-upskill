class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int>ans(n,0);
        map<int,int>mpp;
        for(int i = 0; i<n; i++){
            mpp[a[i]]++;
            mpp[b[i]]++;

            if(i>0) ans[i] = ans[i-1];

            ans[i] += (mpp[a[i]] == 2) + (mpp[b[i]] == 2) - (a[i]==b[i]);
        }

        return ans;
    }
};