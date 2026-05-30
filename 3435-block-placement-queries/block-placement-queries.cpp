class Solution {
public:
    vector<int> seg;

    int con(int i, int ql, int qr, int vl, int vr) {
        if (qr < vl || ql > vr) return 0;
        if (ql <= vl && vr <= qr) return seg[i];
        
        int m = vl + (vr - vl) / 2;
        return max(con(2 * i + 1, ql, qr, vl, m), con(2 * i + 2, ql, qr, m + 1, vr));
    }

    void upd(int i, int a, int u, int vl, int vr) {
        if (vl == vr) {
            seg[i] = u;
            return;
        }
        
        int m = vl + (vr - vl) / 2;
        if (a <= m) {
            upd(2 * i + 1, a, u, vl, m);
        } else {
            upd(2 * i + 2, a, u, m + 1, vr);
        }
        
        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = min(50005, 3 * (int)queries.size() + 5);
        seg.assign(4 * n, 0);
        
        vector<bool> ans;
        set<int> obstacles;
        obstacles.insert(0); 

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                
                auto it = obstacles.upper_bound(x);
                int nxt = (it != obstacles.end()) ? *it : -1;
                
                --it; 
                int prv = *it;
                
                upd(0, x, x - prv, 0, n - 1);
                
                if (nxt != -1) {
                    upd(0, nxt, nxt - x, 0, n - 1);
                }
                
                obstacles.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
                
                auto it = obstacles.upper_bound(x);
                --it;
                int prv = *it;
                
                int max_gap_before_prv = con(0, 0, prv, 0, n - 1);
                int max_gap = max(max_gap_before_prv, x - prv);
                
                ans.push_back(max_gap >= sz);
            }
        }
        
        return ans;
    }
};