class Trie {
public:
    Trie() { }
    
    void insert(string word) {
        Trie* node = this; 
        for(auto ch: word) {
            if(!node->child.count(ch))
                node->child[ch] = new Trie();
            node = node->child[ch];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(auto ch: word) {
            if(!node->child.count(ch))
                return false;
            node = node->child[ch];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto ch: prefix) {
            if(!node->child.count(ch))
                return false;
            node = node->child[ch];
        }
        return true;
    }

private:
    map<char,Trie*> child = {};
    bool isWord = false;  
//     Trie() { }
    
//     void insert(string word) {
//         Trie* node = this; 
//         for(int i=0;i<word.length();i++) {
//             int chIndex = word[i] - 'a';
//             if(!node->child[chIndex])
//                 node->child[chIndex] = new Trie();
//             node = node->child[chIndex];
//         }
//         node->isWord = true;
//     }
    
//     bool search(string word) {
//         Trie* node = this;
//         for(int i=0;i<word.length();i++) {
//             int chIndex = word[i] - 'a';
//             if(!node->child[chIndex])
//                 return false;
//             node = node->child[chIndex];
//         }
//         return node->isWord;
//     }
    
//     bool startsWith(string prefix) {
//         Trie* node = this;
//         for(int i=0;i<prefix.length();i++) {
//             int chIndex = prefix[i] - 'a';
//             if(!node->child[chIndex])
//                 return false;
//             node = node->child[chIndex];
//         }
//         return true;
//     }

// private:
//     Trie* child[26] = {};
//     bool isWord = false;    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */