class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        n = triangle[n-1].size();
        vector<vector<int>> grid(n, vector<int> (n, INT_MAX));
        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                grid[i][j] = triangle[i][j];
            }
        }
        for(int i=1;i<n;i++){
            grid[i][0] += grid[i-1][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                grid[i][j] = min(grid[i-1][j-1], grid[i-1][j]) + grid[i][j];
            }
        }
        int mn = INT_MAX;
        for(int j=0;j<n;j++){
            mn = min(grid[n-1][j], mn);
        }
        return mn;
    }
};