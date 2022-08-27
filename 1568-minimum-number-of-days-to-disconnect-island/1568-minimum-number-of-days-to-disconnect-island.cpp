class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    int row, col;
    bool isValid(int i, int j){
        if(i<0 || j<0 || i>=row || j >= col)
            return false;
        return true;
    }
    void dfs(int x, int y , vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        visited[x][y] = true;
        for(int i=0;i<4;i++){
            int nx = x + DIR[i];
            int ny = y + DIR[i+1];
            if(isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 1){
                dfs(nx, ny, visited, grid);
            }
        }
    }
    int count_islands(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col,false));
        int islands = 0;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(i, j, visited, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int islands = count_islands(grid);
        if(islands == 0 || islands > 1){
            return 0;
        }else {
            //check for 1
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(grid[i][j]){
                        //removing i, j block
                        grid[i][j] = 0;
                        islands = count_islands(grid);
                        //adding the i, j block again
                        grid[i][j] = 1;
                        if(islands == 0 || islands > 1){
                            return 1;
                        }
                    }
                }
            }
        }
        //else return for 2
        return 2;
    }
};