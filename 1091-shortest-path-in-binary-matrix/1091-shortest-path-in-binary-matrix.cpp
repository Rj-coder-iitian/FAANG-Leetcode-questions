class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0 )
            return -1;
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1,-1}, {1, 0}, {1, 1}};
        grid[0][0] = 1;
        q.push({0, 0});
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [x, y] = q.front();
                q.pop();
                if(x == n-1 && y == n-1)
                    return grid[x][y];
                for(auto d : dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if(nx >= 0 && nx < n && ny >=0 && ny < n && grid[nx][ny] == 0){
                        grid[nx][ny] = grid[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};