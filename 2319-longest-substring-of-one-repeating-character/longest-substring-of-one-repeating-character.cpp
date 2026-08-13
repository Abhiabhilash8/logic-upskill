class Solution {
private:
    struct Node {
        char left, right;
        int len, pref, suff, best;
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res;

        res.left = a.left;
        res.right = b.right;
        res.len = a.len + b.len;

        res.pref = a.pref;
        if (a.right == b.left && a.pref == a.len)
            res.pref = a.len + b.pref;

        res.suff = b.suff;
        if (a.right == b.left && b.suff == b.len)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        if (a.right == b.left)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int node, int l, int r, string& s) {
        if (l == r) {
            tree[node] = {s[l], s[l], 1, 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            tree[node] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, ch);
        else
            update(node * 2 + 1, mid + 1, r, idx, ch);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        tree.resize(4 * n);
        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1,
                   queryIndices[i],
                   queryCharacters[i]);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};