// Last updated: 4/5/2026, 11:41:03 AM
class Solution {
public:
     typedef long long ll; 
    
    ll fact[200001];
    bool call_factorial=false;
    void factorial(){
    if(call_factorial)return;
    call_factorial=true;
    fact[0]=1;
    // invfact[0]=modular_inverse(fact[0],M);
    for(ll i=1;i<=12;i++){
        fact[i]=(i*fact[i-1]);
        // invfact[i]=modular_inverse(fact[i],M);}
    }}
    bool isDigitorialPermutation(int n) {
        if(n==0) return false;
        factorial();
        ll t=n;
        ll t2=n;
        vector<int>v,v2;
        ll xr=0;
        while(t2) {v.push_back(t2%10);t2/=10;}
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        t2=0;
        ll po=1;
        for(auto ele: v){
            t2+=(ele*po);
            po*=10;
        }
        
        long long ans=0;
        while(t){
            ans+=fact[t%10];
            t/=10;
        }

        while(ans){
            v2.push_back(ans%10);
            ans/=10;
        }

        sort(v2.begin(),v2.end());
        reverse(v2.begin(),v2.end());
        if(v.size()!=v2.size()) return false;
        for(int i=0;i<v2.size();i++){
            if(v[i]!=v2[i]) return false;
        }

        

        return true;
    }
};