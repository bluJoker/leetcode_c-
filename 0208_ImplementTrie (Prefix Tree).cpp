class TrieNode {
public:
    TrieNode* childNode[26];
    bool isVal;
    TrieNode(): isVal(false) {
        for (int i = 0; i < 26; i++) childNode[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tmp = root;
        for (char c : word) {
            int u = c - 'a';
            if(!tmp->childNode[u]) tmp->childNode[u] = new TrieNode();
            tmp = tmp->childNode[u];
        }
        tmp->isVal = true;
    }
    
    bool search(string word) {
        TrieNode* tmp = root;
        for (char c : word) {
            int u = c - 'a'; 
            tmp = tmp->childNode[u];
            if(!tmp) return false;
        }
        return tmp->isVal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        for (char c : prefix) {
            int u = c - 'a';
            tmp = tmp->childNode[u];
            if(!tmp) return false;
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
 
/**
 * 使用结构体指针模板。用二维数组的话，son[N][26]的N是节点个数，等于单词个数*单词最大长度。N可能很大，不推荐。
 * 在search和startsWith方法中，tmp = tmp->childNode[u]; if(!tmp) return false; 这两步顺序可以判断最后的节点是否非空。
 * 这样在最后判断是否找到单词就不需要再次判断尾节点是否非空了。否则需要return temp? temp->isVal: false;
*/