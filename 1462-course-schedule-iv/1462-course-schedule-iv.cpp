class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<vector<int>> isReachable(n, vector<int>(n, 0));
        vector<bool> ans;
	    //adjacency list
        vector<vector<int>> adj(n);
        for(auto& p: prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                for(auto nbr : adj[cur]){
                    if(visited[i][nbr])  continue;
                    isReachable[i][nbr] = 1;
                    visited[i][nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        for(auto q: queries){
            ans.push_back(isReachable[q[0]][q[1]]);
        }
        return ans;
    }
};