class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
        if(i < 0 || j < 0 || i > m-1 || j > n -1)
            return;
        if(grid[i][j] == '0' ||  visited[i][j])
            return;
        visited[i][j] = true;
        dfs(grid, visited, i+1, j, m, n);
        dfs(grid, visited, i-1, j, m, n);
        dfs(grid, visited, i, j+1, m, n);
        dfs(grid, visited, i, j-1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for(int i=0;i<m;i++){
             for(int j=0;j<n;j++) {
                 if(grid[i][j] == '1' && !visited[i][j]) {
                     dfs(grid, visited, i, j, m, n);
                     res++;
                 }
             }
        }
        return res;
    }
};