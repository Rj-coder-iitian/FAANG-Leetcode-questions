class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<bool>& vis, int u) {
        vis[u] = true;
        int changes = 0;
        for(auto v: adj[u]) {
            if(!vis[abs(v)]){
                changes += dfs(adj, vis, abs(v)) + (v > 0);
            }
        }
        return changes;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(-it[0]);
        }
        vector<bool> vis(n, false);
        return dfs(adj, vis, 0);
    }
};