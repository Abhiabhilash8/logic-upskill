class Solution {
public:
typedef long long ll;
#define M 1000000007


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


    int aag(int u , int v , vector<vector<int>>& adj){
        int mk = 0;
        for(int i=0; i<adj[v].size(); i++){ 
           if(adj[v][i] != u) mk = max(mk , aag(v , adj[v][i] , adj));
        }

        return 1 + mk;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>>adj(n + 1);
        for(auto ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        
        int podugu = aag(-1 , 1 , adj) -1;
        

        return binexp(2 , podugu - 1);


    }
};