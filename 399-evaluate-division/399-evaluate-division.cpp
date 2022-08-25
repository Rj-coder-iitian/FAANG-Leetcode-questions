class Solution {
public:
    void dfs(string s, string d, unordered_map<string,vector<pair<string, double>>>& graph, unordered_set<string>& vis, double& ans, double tmp) {
        vis.insert(s);
        if(s == d){
            ans = tmp;
            return;
        }else {
            for(auto it : graph[s]){
                if(vis.find(it.first) == vis.end()){
                    dfs(it.first, d, graph, vis, ans, tmp*it.second);
                }
            }      
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& v, vector<vector<string>>& q) {
        unordered_map<string,vector<pair<string, double>>> graph;
        for(int i=0;i<eqs.size();i++){
            graph[eqs[i][0]].push_back(make_pair(eqs[i][1], v[i]));
            graph[eqs[i][1]].push_back(make_pair(eqs[i][0], 1/v[i]));
        }
        vector<double> res;
        for(int i=0;i<q.size();i++) {
            unordered_set<string> vis;
            double ans = -1;
            double tmp = 1;
            if(graph.find(q[i][0]) != graph.end()) {
                dfs(q[i][0], q[i][1], graph, vis, ans, tmp);
            }
            res.push_back(ans);
        }
        return res;
    }
};