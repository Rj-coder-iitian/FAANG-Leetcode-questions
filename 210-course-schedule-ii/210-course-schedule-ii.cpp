class Solution {
    int V;
    list<int>* adj;
    bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
        visited[v] = true;
        recStack[v] = true;
        for(auto it = adj[v].begin();it != adj[v].end();it++) {
            if(!visited[*it] && isCyclicUtil(*it, visited, recStack))
                return true;
            if(recStack[*it])
                return true;
        }
        recStack[v] = false;
        return false;
    }
    bool isCyclic() {
        vector<bool> visited(V,false);
        vector<bool> recStack(V, false);
        for(int i=0;i<V;i++){
            if(isCyclicUtil(i, visited, recStack))
                return true;
        }
        return false;
    }
    void topoSortUtil(int v, vector<bool>& visited, vector<int>& ans) {
        visited[v] = true;
        for(auto it = adj[v].begin();it != adj[v].end(); it++) {
            if(!visited[*it])
                topoSortUtil(*it, visited, ans);
        }
        ans.push_back(v);
    }
    vector<int> topoSort(int v) {
        vector<bool> visited(V,false);
        vector<int> ans;
        topoSortUtil(v, visited, ans);
        for(int i=0;i<V;i++){
            if(!visited[i])
                topoSortUtil(i, visited, ans);
        }
        return ans;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        V = numCourses;
        adj = new list<int>[V];
        unordered_map<int, vector<int>> hm;
        
        for(int i=0;i<prerequisites.size();i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            hm[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        if(isCyclic())
            return vector<int>();
        
        int i = 0;
        for(i;i<V;i++){
            if(hm.find(i) == hm.end())
                break;
        }
        
        return topoSort(i);
    }
};