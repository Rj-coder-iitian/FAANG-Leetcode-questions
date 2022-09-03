class TrieNode {
public:
    TrieNode* child[26] = {}; // Use an array instead of vector or set
    bool isWord = false;
    TrieNode() {
        
    }
};

class Trie {
public:
    
    Trie(vector<string> &words) { // call by reference
        root = new TrieNode();
        for(string &w : words) updateTrie(w); // call by reference - use wherever applicable
    }
    
    void updateTrie(string &word) {
        TrieNode* root = getRoot();
        for(char &x : word) {
            int ind = x-'a';
            if(!root->child[ind]) root->child[ind] = new TrieNode();
            root = root->child[ind];
        }
        root->isWord = true;
    }
    
    TrieNode* getRoot() {
        return root;
    }
    
private:
    TrieNode* root;
};

class Solution {
public:
    
    int wordCount = 0;
    
	/* check recursively in a dfs fashion
	- add termination/filteration/return conditions wherever possible. 
	- Eg: index out of bounds, total words already found, marking a word's appearance as false once it is found, using "push_back" instead of + to concatinate strings (check word.push_back(ch); line - "+" takes more time), using 2 arrays instead of 2D vector for storing directions */
	
    void check(vector<vector<char>> &b, TrieNode* root, int i, int j, string word, vector<string> &res) {
        if(root->isWord) { res.push_back(word); root->isWord = false; }
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size() || b[i][j]=='-' || wordCount == res.size()) return;
        if(!root->child[b[i][j]-'a']) return;
        root = root->child[b[i][j]-'a'];
        char ch = b[i][j];
        word.push_back(ch);
        b[i][j] = '-';
        int dirs1[] = {0, 0, 1, -1};
        int dirs2[] = {1, -1, 0, 0};
        for(int ii=0;ii<4;ii++) {
            int di = i + dirs1[ii];
            int dj = j + dirs2[ii];
            check(b, root, di, dj, word, res);
        }
        b[i][j] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        wordCount = words.size();
        Trie* root = new Trie(words);
        vector<string> finres;
        for(int p=0;p<board.size();p++) {
            for(int q=0;q<board[0].size();q++) {
                check(board, root->getRoot(), p, q, "", finres);
            }
        }
        return finres;
    }
};