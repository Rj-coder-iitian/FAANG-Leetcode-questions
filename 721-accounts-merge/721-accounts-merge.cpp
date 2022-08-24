class Solution {
public:
    unordered_map<int, int> f;
    int find(int x) {
        if(!f.count(x)) f[x] = x;
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) {
            f[x] = y;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        for(int i=0;i<n;i++) {
            int sz = accounts[i].size();
            for(int j = 1;j<sz;j++) {
                if(mp.find(accounts[i][j]) != mp.end()) {
                    uni(mp[accounts[i][j]], i);
                }
                mp[accounts[i][j]] = i;
            }
        }
        vector<set<string>> vec(n);
        for(int i=0;i<n;i++) {
            int sz = accounts[i].size();
            for(int j = 1;j<sz;j++) {
                vec[find(mp[accounts[i][j]])].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++) {
            vector<string> temp;
            if(vec[i].size() > 0){
                temp.push_back(accounts[i][0]);
                for(auto s = vec[i].begin(); s != vec[i].end(); s++) {
                    temp.push_back(*s);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};