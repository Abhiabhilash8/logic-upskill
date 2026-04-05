// Last updated: 4/5/2026, 11:42:19 AM
class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.length();
        int szero=0;
        for(int c: s) if(c=='0') szero++;
        if(szero==0) return 0;
        vector<int>op(n+1,-1);
        op[szero]=0;
        queue<int>q;
        q.push(szero);
        set<int>odd,even;
        for(int c=0;c<=n;c++){
            if(c&1) odd.insert(c);
            else even.insert(c);
        }

        if(szero&1) odd.erase(szero);
        else even.erase(szero);

        while(q.size()){
            int z=q.front();
            q.pop();
            int maxnz=z+k-2*max(0,k-n+z);
            int minnz=z+k-2*min(k,z);

            set<int>&curset=(minnz&1)? odd:even;
            auto it=curset.lower_bound(minnz);

            while(it!=curset.end() && *it<=maxnz){
                int nz=*it;
                op[nz]=op[z]+1;
                if(nz==0) return op[nz];
                q.push(nz);
                auto temp=it;
                ++it;
                curset.erase(temp);
            }
        }

        return -1;
    }
};