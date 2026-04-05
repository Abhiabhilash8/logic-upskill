// Last updated: 4/5/2026, 11:45:19 AM
class Solution {
public:

string solve(string s){
    int st=0,n=s.size();
    vector<string>v;
    int pre=0;
    for(int i=0;i<n;i++){
        pre+=(s[i]=='1'? 1:-1);

        if(pre==0){
            v.push_back("1"+solve(s.substr(st+1,i-st-1))+"0");
            st=i+1;
        }

    }
    
        sort(v.begin(),v.end(),greater<string>());
        string ans;
        for(auto bdk: v) ans+=bdk;
        return ans;
}
    string makeLargestSpecial(string s) {
        return solve(s);
    }
};