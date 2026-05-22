class Solution {
public:

// Digit Trie — O(10) children per node (digits 0-9)
// insert digits of a number, search common prefix length
struct DigitTrie {
    struct Node {
        int children[10];
        Node() { fill(children, children + 10, -1); }
    };
    vector<Node> nodes;

    DigitTrie() { nodes.push_back(Node()); }

    void insert(int n) {
        string s = to_string(n);
        int cur = 0;
        for (char c : s) {
            int d = c - '0';
            if (nodes[cur].children[d] == -1) {
                nodes[cur].children[d] = nodes.size();
                nodes.push_back(Node());
            }
            cur = nodes[cur].children[d];
        }
    }

    int commonPrefix(int n) {
        string s = to_string(n);
        int cur = 0, len = 0;
        for (char c : s) {
            int d = c - '0';
            if (nodes[cur].children[d] == -1) break;
            cur = nodes[cur].children[d];
            len++;
        }
        return len;
    }
};
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        DigitTrie t;
        for(int i = 0; i<arr1.size(); i++) t.insert(arr1[i]);
        int ans = 0;
        for(int i = 0; i<arr2.size(); i++) ans = max( ans , t.commonPrefix(arr2[i]));

        return ans;
    }
};