// Last updated: 4/5/2026, 11:40:46 AM
class Solution {
public:
typedef long long ll;
#define vll vector<ll>
#define pb push_back
#define M 1000000007
#define INF LLONG_MAX
#define tot(a) a.begin(),a.end()
#define minV *min_element
#define maxV *max_element
typedef pair<ll,ll> prll;
typedef pair<int,int> prii;
template<class T>void inp(vector<T>&a){for(auto &x:a)cin>>x;}
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
ll fact[200001],invfact[200001];
bool call_factorial=false;
void factorial(){
    if(call_factorial)return;
    call_factorial=true;
    fact[0]=1;
    invfact[0]=modular_inverse(fact[0],M);
    for(ll i=1;i<=200000;i++){
        fact[i]=(i*fact[i-1])%M;
        invfact[i]=modular_inverse(fact[i],M);}}
ll nCr(ll n,ll r){
    if(!call_factorial)factorial();
    if(n<r)return 0;
    ll num=fact[n];
    ll den=(invfact[r]*invfact[n-r])%M;
    return (num*den)%M;} 
vector<int> z_function(string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);}
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;}
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }}return z;}
// ---------------------------------
    void getf(long long n,vector<ll>&f){
        int i=1;
        for(i=1;i*i<n;i++){
            if(n%i==0){
                f.pb(i);
                f.pb(n/i);
            }
        }

        if(i*i==n) f.pb(i);
    }


    bool c(int st,int end,vector<int>&nums,int &curmin,int &curmax){
        curmin=nums[st];
        curmax=nums[st];

        int d=0;
        for(int i=st+1;i<=end;i++){
            curmin=min(curmin,nums[i]);
            curmax=max(curmax,nums[i]);;
            if(nums[i]<nums[i-1]) d++;
        }

        return d==0 || (d==1 && nums[st]>=nums[end]);
    }



    int sortableIntegers(vector<int>& nums) {
        vector<ll>fac;
        getf(nums.size(),fac);
        int n=nums.size(),ans=0;


        for(int j=0;j<fac.size();j++){
            int k=fac[j],f=0;
            int prevmax=-1,curmax,curmin;
            for(int i=0;i<n;i+=k){
                curmin=INT_MAX,curmax=INT_MIN;
                if(!c(i,i+k-1,nums,curmin,curmax) || curmin<prevmax) {
                    f=1;
                    break;
                }   
                prevmax=curmax;             
            }
            if(!f) ans+=k;
        }

        return ans;
    }
};