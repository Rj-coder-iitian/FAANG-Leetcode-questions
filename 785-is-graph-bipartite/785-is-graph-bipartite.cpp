class Solution {
public:
    bool dfs(vector<int>& colors, vector<vector<int>>& graph, int color, int cur){
        if(colors[cur] != 0)
            return colors[cur] == color;
        colors[cur] = color;
        for(auto& v: graph[cur]) {
            if(!dfs(colors, graph, -color, v))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,0);
        for(int i=0;i<n;i++){
            if(colors[i] == 0 && !dfs(colors, graph, 1, i))
                return false;
        }
        return true;
    }
};