class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> res, int u, vector<bool> vis) {
        if(u == n-1){
            res.push_back(u);
            ans.push_back(res);
            return;
        }
        vis[u] = true;
        res.push_back(u);
        for(auto v: graph[u]){
            if(!vis[v])
                dfs(graph, ans, res, v, vis);
        }
        res.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> vis(n, false);
        dfs(graph, ans, res, 0, vis);
        return ans;
    }
};