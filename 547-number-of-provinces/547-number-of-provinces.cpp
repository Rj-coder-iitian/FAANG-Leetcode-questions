class Solution {
public:
    vector<int>parent;
    vector<int> rank;
 	int find(int x) {
        if(x == parent[x])
            return x;
        parent[x] = find(parent[x]);
 		return parent[x];
 	}
    void unionFun (int x, int y) {
        int x_rep = find(x), y_rep = find(y);
        if(x_rep == y_rep)
            return;
        if(rank[x_rep] < rank[y_rep]) parent[x_rep] = y_rep;
        else if(rank[x_rep] > rank[y_rep]) parent[y_rep] = x_rep;
        else {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

 		parent.resize(n+1, 0);
        rank.resize(n+1, 0);
 		for (int i = 0; i <= n; i++)
 			parent[i] = i;
        
        vector<int>res(2, 0);
 		for (int i = 0; i < n; i++) {
 			for(int j=i+1;j<n;j++) {
                if(isConnected[i][j]){
                    unionFun(i+1, j+1);
                }
            }
 		}
        unordered_set<int> ans;
    
        for(int i=0;i<n;i++) {
            if(ans.find(find(i+1)) == ans.end())
                ans.insert(find(i+1));
        }

 		return ans.size();
    }
};