class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    int n;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x, int y){
        vis[x][y] = true;
        for(int i=0;i<4;i++){
            int nx = x + DIR[i];
            int ny = y + DIR[i+1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny])
                dfs(grid, vis, nx, ny);
        }
    }
    int bfs(vector<vector<int>> grid, vector<vector<bool>> vis, int x, int y) {
        int res = 0;
        queue<pair<int,int>> q;
        q.push({x, y});
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [cx, cy] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = cx + DIR[i];
                    int ny = cy + DIR[i+1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        if(!vis[nx][ny] && grid[nx][ny])
                            return res;
                        else if(grid[nx][ny] == 0){
                            grid[nx][ny] = 1;
                            q.push({nx, ny});
                            vis[nx][ny] = true;
                        }
                    }
                }
            }
            res++;
        }
        return INT_MAX;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<vector<bool>> alt_vis(n, vector<bool>(n, false));
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] && !flag){
                    dfs(grid, vis, i, j);  
                    flag = true;
                } else if(!vis[i][j] && grid[i][j] && flag){
                    dfs(grid, alt_vis, i, j);  
                }
            }
        }
        vector<pair<int,int>> v1, v2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]){
                    v1.push_back({i, j});
                }
                else if(alt_vis[i][j]){
                    v2.push_back({i, j});
                }
            }
        }
        int res = INT_MAX;
        for(int i=0;i<v1.size();i++) { 
            for(int j=0;j<v2.size();j++) {
                int tmp = abs(v2[j].second - v1[i].second) + abs(v2[j].first - v1[i].first);
                res = min(res, tmp);
            }
        }
        return res - 1;
    }
};