// Last updated: 4/5/2026, 11:46:56 AM
struct Node{
    Node *links[26];
    bool f;

    bool contains(char ch){
        if(links[ch-'a']) return true;
        return false;
    }

    void put(char ch){
        links[ch-'a']=new Node();
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        f=true;
    }

};

class Trie {
    private: Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])){
                node->put(word[i]);
            }

            node=node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])) return false;

            node=node->get(word[i]);
        }

        return node->f;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->contains(prefix[i])) return false;

            node=node->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */