class Solution {
public:
    int m, n;
    vector<int> DIR = {0, 1, 0, -1, 0};
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, queue<vector<int>>& q) {
        while(!q.empty()){
            vector<int> tmp = q.front();
            q.pop();
            vis[tmp[0]][tmp[1]] = true;
            for(int i=0;i<4;i++) {
                int nx = tmp[0] + DIR[i];
                int ny = tmp[1] + DIR[i+1];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny] || heights[nx][ny] < heights[tmp[0]][tmp[1]])
                    continue;
                q.push({nx, ny});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pVis(m, vector<bool>(n, false));
        vector<vector<bool>> aVis(m, vector<bool>(n, false));
        queue<vector<int>> pacificQ;
        queue<vector<int>> atlanticQ;
        for(int i=0;i<m;i++){
            pVis[i][0] = true;
            aVis[i][n-1] = true;
            pacificQ.push({i,0});
            atlanticQ.push({i,n-1});
        }
        for(int i=0;i<n;i++){
            pVis[0][i] = true;
            aVis[m-1][i] = true;
            pacificQ.push({0,i});
            atlanticQ.push({m-1, i});
        }
        bfs(heights, pVis, pacificQ);
        bfs(heights, aVis, atlanticQ);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(aVis[i][j] && pVis[i][j]){
                    vector<int> tmp = {i, j};
                    ans.push_back(tmp);
                }
            }
        }
        return ans;                   
    }
};