class Solution {
public:
    int count;
    unordered_map<int, set<pair<int, int>>> mp;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
        if(i < 0 || j < 0 || i > m-1 || j > n -1)
            return;
        if(grid[i][j] == 0 ||  visited[i][j])
            return;
        visited[i][j] = true;
        mp[count].insert({i,j});
        dfs(grid, visited, i+1, j, m, n);
        dfs(grid, visited, i-1, j, m, n);
        dfs(grid, visited, i, j+1, m, n);
        dfs(grid, visited, i, j-1, m, n);
    }
    int numIslands(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        count = 0;
        for(int i=0;i<m;i++){
             for(int j=0;j<n;j++) {
                 if(grid[i][j] == 1 && !visited[i][j]) {
                     dfs(grid, visited, i, j, m, n);
                     count++;
                 }
             }
        }
        return count;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int islands = numIslands(grid2);
        int res = 0;
        for(int i=0;i<islands;i++){
            bool flag = true;
            for(auto p = mp[i].begin(); p != mp[i].end(); p++){
                int x = (*p).first;
                int y = (*p).second;
                if(grid1[x][y] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag)
                res++;
        }
        return res;
    }
};