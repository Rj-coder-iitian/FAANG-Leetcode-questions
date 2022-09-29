class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int left = INT_MAX, mid = INT_MAX, right = INT_MAX;
                if(j > 0)
                    left = matrix[i-1][j-1];
                mid = matrix[i-1][j];
                if(j < n-1)
                    right = matrix[i-1][j+1];
                matrix[i][j] += min({left, mid, right});
            }
        }
        int res = INT_MAX;
        for(int j=0;j<n;j++){
            res = min(res, matrix[n-1][j]);
        }
        return res;
    }
};