class Solution {
public:
    int row, col;
    void cornerDfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if(i < 0 || j < 0 || i >= row || j >= col)
            return;
        if(grid[i][j] == 1 || visited[i][j])
            return;
        grid[i][j] = 1;
        visited[i][j] = true;
        cornerDfs(grid, visited, i+1, j);
        cornerDfs(grid, visited, i-1, j);
        cornerDfs(grid, visited, i, j+1);
        cornerDfs(grid, visited, i, j-1);
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if(i < 0 || j < 0 || i >= row || j >= col)
            return;
        if(grid[i][j] == 1 || visited[i][j])
            return;
        grid[i][j] = 1;
        visited[i][j] = true;
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if((i == 0 || j == 0 || i == row-1 || j == col-1) && grid[i][j] == 0 && !visited[i][j]){
                    cornerDfs(grid, visited, i, j);
                }
            }
        }
        visited.resize(row, vector<bool>(col, false));
        int count = 0;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == 0 && !visited[i][j]){
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};