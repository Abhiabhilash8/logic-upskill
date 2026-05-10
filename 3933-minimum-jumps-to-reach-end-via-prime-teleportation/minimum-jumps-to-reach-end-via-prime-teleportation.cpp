vector<int> spf;
vector<int> mpp[1000005];
vector<int>ac;

void sieve(int n) {
    if(!spf.empty()) return;
    spf.resize(n + 1);
    for (int i = 2; i <= n; i++) spf[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

void getPrimeFactors(int x,int ind) {
    while (x > 1) {
        int prime = spf[x];
        if(mpp[prime].empty()) ac.push_back(prime);
        mpp[prime].push_back(ind);
        while (x % prime == 0) {
            x /= prime; 
        }
    }
}
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        sieve(1e6+1);
        for(int i = 0; i<nums.size();i++) getPrimeFactors(nums[i] , i);
        int ans = 0;
        queue<int>q;
        q.push(0);
        bitset<1000005> vis;
        vis[0] = 1;
        vis[0] =  1;
        while(q.size()){
            int cursize = q.size();
            while(cursize--){
                int curind = q.front();
                q.pop();
                if(curind == n-1){
                    for(auto p: ac) mpp[p].clear();
                    ac.clear();
                    return ans;
                }
                if(curind>0 && !vis[curind-1]){
                    q.push(curind-1);
                    vis[curind-1] = 1;
                }
                if(!vis[curind+1]){
                    q.push(curind+1);
                    vis[curind+1] = 1;
                } 

                if( nums[curind] > 1 && spf[nums[curind]] == nums[curind]){
                    for(auto pos: mpp[nums[curind]]){
                        if(!vis[pos]){
                            vis[pos] = 1;
                            q.push(pos);
                        }
                    }
                    mpp[nums[curind]].clear();
                }
            }

            ans++;
        }
        for(int p: ac) mpp[p].clear();
        return ans;

    }
};
auto fastIO = []() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    return 0;

}();