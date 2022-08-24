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
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        V = numCourses;
        adj = new list<int>[V];
        
        for(int i=0;i<prerequisites.size();i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        if(isCyclic())
            return false;
        return true;
    }
};