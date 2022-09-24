class Solution {
public:
    int cnt = 0, n, m;
    vector<int> DIR = {0, 1, 0, -1, 0};
    void solve(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x, int y, int &blox, int &subCount) {
        vis[x][y] = true;
        subCount++;
        if(grid[x][y] == 2 && subCount == blox)
            cnt++;
        else {
            for(int i=0;i<4;i++){
                int nx = x + DIR[i];
                int ny = y + DIR[i+1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != -1 && !vis[nx][ny])
                    solve(grid, vis, nx, ny, blox, subCount);
            }
        }
        vis[x][y] = false;
        subCount--;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int x=0,y=0, blox = 0, subCount = 0;
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
                if(grid[i][j] == -1)
                    blox++;
            }
        }
        blox = (n*m) - blox;
        solve(grid, vis, x, y, blox, subCount);
        return cnt;
    }
};