class Solution {
public:
    void dfs(unordered_map<string, multiset<string>>& graph, vector<string>& res, string airport) {
        while(graph[airport].size()){
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(graph, res, next);
        }
        res.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for(auto& t: tickets){
            graph[t[0]].insert(t[1]);
        }
        vector<string> res;
        dfs(graph, res, "JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};