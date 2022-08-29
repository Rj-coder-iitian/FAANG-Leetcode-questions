class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n);
        for(int i=0;i<redEdges.size();i++){
            graph[redEdges[i][0]].push_back({redEdges[i][1], 0}); // 0 denotes red edge
        }
        for(int i=0;i<blueEdges.size();i++){
            graph[blueEdges[i][0]].push_back({blueEdges[i][1], 1}); // 1 denotes a blue edge
        }
        vector<int> dist(n, -1);
        queue<vector<int>> q;
        q.emplace(vector<int>{0, 0, -1});  // storing info {node, dist, previous edge}
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            dist[curr[0]] = dist[curr[0]] != -1 ? dist[curr[0]] : curr[1];
            for(auto& it: graph[curr[0]]) {
                if(curr[2] != it.second && it.first != -1){
                    q.emplace(vector<int>{it.first, curr[1] + 1, it.second});
                    it.first = -1;
                }
            }
        }
        return dist;
    }
};