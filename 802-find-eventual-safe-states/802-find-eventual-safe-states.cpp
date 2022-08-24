class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& dp, int src) {
        if(dp[src])
            return dp[src] == 1;
        
        dp[src] = -1;
        
        for(auto v: graph[src]){
            if(!dfs(graph, dp, v))
                return false;
        }
        
        dp[src] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, 0);
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(dfs(graph, dp, i))
                ans.push_back(i);
        }
        return ans;
    }
};