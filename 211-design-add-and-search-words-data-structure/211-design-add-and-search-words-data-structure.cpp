class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        isEnd = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
public:
    WordDictionary() { }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto ch: word) {
            if(!curr->children[ch - 'a'])
                curr->children[ch - 'a'] = new TrieNode();
            curr = curr->children[ch - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return search(word.c_str(), root);
    }
    
private:
    TrieNode* root = new TrieNode();
    bool search(const char* word, TrieNode* node) {
        for(int i = 0; word[i] && node; i++) {
            if(word[i] != '.')
                node = node->children[word[i] - 'a'];
            else {
                TrieNode* temp = node;
                for(int j=0;j<26;j++) {
                    node = temp->children[j];
                    if(search(word + i + 1, node))
                        return true;
                }
            }
        }
        return node && node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */