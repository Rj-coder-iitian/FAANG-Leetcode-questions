class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> graph;
        for(int i=0;i<roads.size();i++) {
            graph[roads[i][0]].insert(roads[i][1]);
            graph[roads[i][1]].insert(roads[i][0]);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int count = graph[i].size() + graph[j].size();
                if(graph[i].count(j))
                    count--;
                res = max(res, count);
            }
        }
        return res;
    }
};