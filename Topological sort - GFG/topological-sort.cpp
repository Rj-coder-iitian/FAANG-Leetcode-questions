//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
// 	void topoSortUtil(int u, vector<bool>& vis, vector<int> adj[], stack<int>& st) {
// 	    vis[u] = true;
// 	    for(auto v: adj[u]){
// 	        if(vis[v] == false)
// 	            topoSortUtil(v, vis, adj, st);
// 	    }
// 	    st.push(u);
// 	}
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    stack<int> st;
// 	    vector<bool> vis(V, false);
// 	    for(int i=0;i<V;i++) {
// 	        if(vis[i] == false)
// 	            topoSortUtil(i, vis, adj, st);
// 	    }
// 	    vector<int> res;
// 	    while(st.size() > 0){
// 	        res.push_back(st.top());
// 	        st.pop();
// 	    }
// 	    return res;
// 	}
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> res;
	    vector<int> indegree(V, 0);
	    queue<int> q;
	    int cnt = 0;
	    for(int u=0;u<V;u++) {
	        for(auto v: adj[u])
	            indegree[v]++;
	    }
	    for(int u=0;u<V;u++){
	        if(indegree[u] == 0)
	            q.push(u);
	    }
	    while(!q.empty()) {
	        int u = q.front();
	        q.pop();
	        res.push_back(u);
	        for(auto v: adj[u]){
	            if(--indegree[v] == 0)
	                q.push(v);
	        }
	        cnt++;
	    }
	    if(cnt != V){
	        cout << "Cycle is present in the graph";
	    }
	    return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends