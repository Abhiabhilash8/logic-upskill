// Last updated: 4/5/2026, 11:44:12 AM
class Solution {
public:
string f(int n){
    if(n==1) return "0";
    string x=f(n-1);
    string y=x;
    reverse(y.begin(),y.end());
    for(int i=0;i<y.size();i++){
        y[i]=y[i]=='1'? '0':'1';
    }
    return x+"1"+y;
}
    char findKthBit(int n, int k) {
        string s=f(n);
        return *(s.begin()+k-1);
    }
};