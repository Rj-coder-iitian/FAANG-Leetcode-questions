class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n, int& count) {
        if(i < 0 || j < 0 || i > m-1 || j > n -1)
            return;
        if(grid[i][j] == 0 ||  visited[i][j])
            return;
        visited[i][j] = true;
        count++;
        dfs(grid, visited, i+1, j, m, n, count);
        dfs(grid, visited, i-1, j, m, n, count);
        dfs(grid, visited, i, j+1, m, n, count);
        dfs(grid, visited, i, j-1, m, n, count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int area = 0;
        for(int i=0;i<m;i++){
             for(int j=0;j<n;j++) {
                 if(grid[i][j] == 1 && !visited[i][j]) {
                     int count = 0;
                     dfs(grid, visited, i, j, m, n, count);
                     area = max(area, count);
                 }
             }
        }
        return area;
    }
};