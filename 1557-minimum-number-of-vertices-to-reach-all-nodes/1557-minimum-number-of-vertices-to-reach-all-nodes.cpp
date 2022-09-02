class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> inEdges(n, false);
        for(int i=0;i<edges.size();i++) {
            inEdges[edges[i][1]] = true;
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(!inEdges[i])
                ans.push_back(i);
        }
        return ans;
    }
};