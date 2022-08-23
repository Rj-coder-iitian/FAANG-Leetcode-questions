class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz = connections.size();
        if(sz < n - 1)
            return -1;
        //Step 1: initialising the parent;
        vector<int> parent(n, 0);
        for(int i=0;i<n;i++)
            parent[i] = i;
        
        int groups = n;
        for(int i=0;i<sz;i++) {
            int x = find(connections[i][0], parent);
            int y = find(connections[i][1], parent);
            if(x != y) {
                parent[x] = y;
                groups--;
            }
        }
        return groups - 1;
    }
private:
    int find(int x, vector<int>& parent) {
        return x == parent[x] ? x : find(parent[x], parent);
    }
};