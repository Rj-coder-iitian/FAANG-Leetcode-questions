class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // Base case when matrix is of zero size.
        if(matrix.size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        int sz_max = 0; // This will store the maximum square length possible.
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                // For 1st row and column the value will be as it is, and when matrix value is 0 then also dp value shoud be 0.
                if(!i || !j || matrix[i][j] == '0')
                    dp[i][j] = matrix[i][j] - '0';
                else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
                sz_max = max(sz_max, dp[i][j]);
            }
        }
        return sz_max * sz_max;
    }
};