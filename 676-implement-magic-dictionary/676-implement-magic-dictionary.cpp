class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        isEnd = false;
        memset(children, NULL, sizeof(children));
    }
};
class MagicDictionary {
public:
    TrieNode* root;
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word : dictionary)
            addWord(word);
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto ch: word) {
            if(!curr->children[ch - 'a'])
                curr->children[ch - 'a'] = new TrieNode();
            curr = curr->children[ch - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool helper(string word) {
        int n = word.size();
        TrieNode* t = root;
        for(int i=0;i<n;i++) {
            if(!t->children[word[i] - 'a'])
                return false;
            t = t->children[word[i] - 'a'];
        }
        return t->isEnd;
    }
    
    bool search(string searchWord) {
        int n = searchWord.size();
        string word = searchWord;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++) {
                if('a' + j == searchWord[i])
                    continue;
                word[i] = 'a' + j;
                if(helper(word))
                    return true;
            }
            word[i] = searchWord[i];
        }
        return false;
    }
};

// bool helper(string word)
//     {
//         T* node=root;
//         int n=word.size();
//         for(int i=0;i<n;i++)
//         {
//             if(!node->c[word[i]-'a'])
//                 return false;
//             node=node->c[word[i]-'a'];
//         }
//         return node->end;
//     }
    
//     bool search(string sword) {
//         int n=sword.size();
//         string word=sword;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<26;j++)
//             {
//                 if('a'+j==sword[i])
//                     continue;
//                 word[i]='a'+j;
//                 if(helper(word))
//                     return true;
//             }
//             word[i]=sword[i];
//         }
//         return false;
//     }

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */