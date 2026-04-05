// Last updated: 4/5/2026, 11:41:44 AM
class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        long long ans=0;
        vector<int>temp;
        for(int i=0;i<t1.size();i++){
            if(t1[i]>=t2[i]){
                ans+=t1[i];
                k--;
            }else{
                ans+=t2[i];
                temp.push_back(t1[i]-t2[i]);
            }
        }

        if(k<=0) return ans;

        sort(temp.begin(),temp.end());
        int pt=temp.size()-1;
        while(pt>=0 && k--){
            ans+=temp[pt--];
        }

        return ans;
    }
};