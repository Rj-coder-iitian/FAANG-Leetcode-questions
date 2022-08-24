class Solution {
public:
    vector<int>DIR = {0, 1, 0, -1, 0};
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
         // step 1 : pushing all coordinates of land
        for(int i=0;i<row;i++) 
            for(int j=0;j<col;j++) 
                if(grid[i][j] == 1)
                    q.emplace(i, j);
        
        // if matrix has no water then ans = -1 so return 
        if(q.size() == row*col)
            return -1;
        
        int dist = 0;
         while(!q.empty()) {
             int size = q.size();
             dist++;
             while(size--) {
                 auto [r, c] = q.front();
                 q.pop();
                 for(int i=0;i<4;i++){
                     int x = r + DIR[i];
                     int y = c + DIR[i+1];
                     if(x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 0){
                         grid[x][y] = 1;
                         q.emplace(x, y);
                     }
                 }
             }
         }
        return dist - 1;
    }
};