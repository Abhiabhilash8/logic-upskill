struct TrieNode {
    int children[26];
    int best_idx;  // best container index at this node

    TrieNode() {
        fill(begin(children), end(children), -1);
        best_idx = -1;
    }
};


class Trie {
private:
    vector<TrieNode> nodes;

    bool isBetter(const vector<string>& container, int new_idx, int cur_idx) {
        if (cur_idx == -1) return true;
        int new_len = container[new_idx].size();
        int cur_len = container[cur_idx].size();
        if (new_len != cur_len) return new_len < cur_len;
        return new_idx < cur_idx;  // earlier index wins on tie
    }

public:
    Trie() {
        nodes.emplace_back();  // root is index 0
    }

    void insert(const string& word, int idx, const vector<string>& container) {
        int cur = 0;  // start at root

        // update root (handles zero common suffix case)
        if (isBetter(container, idx, nodes[cur].best_idx))
            nodes[cur].best_idx = idx;

        for (char ch : word) {
            int c = ch - 'a';
            if (nodes[cur].children[c] == -1) {
                nodes[cur].children[c] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[c];
            if (isBetter(container, idx, nodes[cur].best_idx))
                nodes[cur].best_idx = idx;
        }
    }

    int query(const string& word) {
        int cur = 0;  // start at root
        for (char ch : word) {
            int c = ch - 'a';
            if (nodes[cur].children[c] == -1)
                break;  // can't go deeper, use current node's best
            cur = nodes[cur].children[c];
        }
        return nodes[cur].best_idx;
    }
};


class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;

        for (int i = 0; i < wordsContainer.size(); i++) {
            string rev = wordsContainer[i];
            reverse(rev.begin(), rev.end());
            trie.insert(rev, i, wordsContainer);
        }

        vector<int> ans;
        for (auto& word : wordsQuery) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            ans.push_back(trie.query(rev));
        }

        return ans;
    }
};