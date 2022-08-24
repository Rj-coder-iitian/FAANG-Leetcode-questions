class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& mp, vector<int>& informTime, int i, int& res, int curr) {
        curr += informTime[i];
        res = max(res, curr);
        for (auto it = mp[i].begin(); it != mp[i].end(); it++)
 			dfs(mp, informTime, *it, res, curr);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++)
            if(manager[i] != -1)
                mp[manager[i]].push_back(i);
        int res = 0, curr = 0;
        dfs(mp, informTime, headID, res, curr);
        return res;
    }
};