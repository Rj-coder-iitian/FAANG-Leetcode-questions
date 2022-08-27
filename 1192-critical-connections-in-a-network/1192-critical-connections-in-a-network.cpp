class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& graph, vector<int>& low, vector<int>& disc, vector<int>& parent, vector<vector<int>>& bridge, int u) {
        static int timer = 0;
        disc[u] = low[u] = timer++;
        for(auto v: graph[u]){
            if(disc[v] == -1){
                parent[v] = u;
                dfs(graph,low, disc, parent, bridge, v);
                // Update low value of parent
                low[u] = min(low[u], low[v]);
                
                if(low[v] > disc[u]){
                    vector<int> tmp = {u, v};
                    bridge.push_back(tmp);
                }
                
            } else if(v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> graph;
        for(auto& it: connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<vector<int>> bridge;
        vector<int> low(n,-1), disc(n,-1), parent(n, -1);
        for(int i=0;i<n;i++)
            if(disc[i] == -1)
                dfs(graph, low, disc, parent, bridge, i);
        return bridge;
    }
};