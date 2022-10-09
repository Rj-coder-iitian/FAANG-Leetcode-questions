class Solution {
public:
    class Trienode{
        public:
        Trienode* v[26];
        vector<int> dp;
        bool isEnd;
        Trienode(){
            memset(v,NULL,sizeof v);
            isEnd=false;
            dp.resize(26,0);
        }
    };
    class Trie {
    public:
        Trienode* root;
        Trie() {
            root=new Trienode();
        }

        void insert(string word) {
            Trienode* curr=root;
            int n = word.size();
            for(int i=0;i<n;++i){
                int idx=word[i]-'a';
                if(curr->v[idx]==NULL)
                    curr->v[idx]=new Trienode();
                curr->dp[idx] += 1;
                curr=curr->v[idx];
            }
            curr->isEnd=true;
        }
        
        int calculate(string s) {
            Trienode* curr=root;
            int ans=0;
            bool flag=false;
            int n = s.size();
            for(int i=0;i<n;++i){
                int idx=s[i]-'a';
                ans += curr->dp[idx];
                curr=curr->v[idx];
            }
            return ans;
        }
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        int sz=words.size();
        Trie obj = Trie();
        vector<int> res(sz);
        for(int i=0;i<sz;i++)
            obj.insert(words[i]);
        for(int i=0;i<sz;++i)
            res[i] = obj.calculate(words[i]);
        return res;
    }
};
