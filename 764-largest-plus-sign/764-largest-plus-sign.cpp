class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int> (n,1));
        for(auto& m: mines)
            grid[m[0]][m[1]] = 0;
        vector<vector<int>> left, right, top, bottom;
        left = right = top = bottom = grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x = n - i - 1;
                int y = n - j - 1;
                if(j > 0 && left[i][j]) left[i][j] += left[i][j-1];
                if(i > 0 && top[i][j]) top[i][j] += top[i-1][j];
                if(y < n-1 && right[x][y]) right[x][y] += right[x][y+1];
                if(x < n-1 && bottom[x][y]) bottom[x][y] += bottom[x+1][y];   
            }
        }
        int plus_sign = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                plus_sign = max(plus_sign, min({left[i][j], top[i][j], right[i][j], bottom[i][j]}));
            }
        }
        return plus_sign;
    }
};