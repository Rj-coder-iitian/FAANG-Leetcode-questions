class Solution {
public:
    void dfs(unordered_map<int, vector<int>> mp, vector<int>& informTime, int i, int& res, int curr) {
        curr += informTime[i];
        res = max(res, curr);
        for (auto it = mp[i].begin(); it != mp[i].end(); it++)
 			dfs(mp, informTime, *it, res, curr);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++)
            mp[manager[i]].push_back(i);
        int res = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(headID, 0));
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                auto curr = q.front();
                q.pop();
                int time = curr.second + informTime[curr.first];
                res = max(res, time);
                for(auto m: mp[curr.first])
                    q.push(make_pair(m, time));
            }
        }
        return res;
    }
};