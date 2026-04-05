// Last updated: 4/5/2026, 11:44:08 AM
#define ll long long
int M=1e9+7;
ll lcm(ll a, ll b){return a/__gcd(a,b)*b;}
ll gcd(ll a,ll b){return __gcd(a,b);}
bool isprime(ll n){if(n<=1)return false;
    else if(n<=3)return true;
    else if(n%2==0 || n%3==0)return false;
    for(ll i=5;i*i<=n;i+=6)
    if(n%i==0 || n%(i+2)==0)return false;return true;} 
ll binexp(ll a,ll b,ll mod2=M){ll res=1;a%=mod2;
    while(b){if(b%2)res=(res*a)%mod2;a=(a*a)%mod2;b>>=1;}
    return res;}
ll modular_inverse(ll a,ll mod2=M)/*Fermat's*/{return binexp(a,mod2-2,mod2);}


class Fancy {
public:
#define ll long long

    ll a=1,b=0;
    vector<int>seq;


    Fancy() {}
    
    void append(int val) {
        int dif=(val%M-b%M+M)%M;
        int toadd=(dif%M * modular_inverse(a)%M)%M;
        seq.push_back(toadd);
    }
    
    void addAll(int inc) {
        b=(b%M + inc%M)%M;
        // cout<<"a and b add: "<<a<<" "<<b<<endl;
    }
    
    void multAll(int m) {
        a=(a%M * m%M)%M;
        b=(b%M * m%M)%M;
        // cout<<"a and b mul: "<<a<<" "<<b<<endl;
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size()) return -1;
        // cout<<seq[idx]<<" for ind: "<<idx<<endl;
        // cout<<a<<" "<<b<<endl;
        int x=seq[idx];
        int pro=(a%M * x%M)%M;
        // cout<<(pro%M + b%M)%M<<endl;
        return (pro%M + b%M)%M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */