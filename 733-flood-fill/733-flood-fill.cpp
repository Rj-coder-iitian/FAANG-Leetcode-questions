class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image.empty())
            return image;
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int origColor = image[sr][sc];
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                auto p = q.front();
                q.pop();
                image[p.first][p.second] = color;
                visited[p.first][p.second] = true;
                for(int k=0;k<4;k++) {
                    int x = p.first + dir[k][0];
                    int y = p.second + dir[k][1];
                    if(isValid(x, y, m, n) && image[x][y] == origColor && !visited[x][y])
                        q.push(make_pair(x,y));
                }
            }
        }
    return image;
    }
};