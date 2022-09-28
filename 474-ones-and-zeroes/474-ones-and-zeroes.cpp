class Solution {
public:
    int findMaxForm(vector<string>& strs, int nZeros, int nOnes) {
        vector<vector<int>> dp(nZeros+1, vector<int>(nOnes+1));
        int i,j;
        for(auto& s:strs){
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.length() - ones;
            for(i=nZeros;i>=zeros;i--){
                for(j=nOnes;j>=ones;j--){
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]);
                }
            }
        }
        return dp[nZeros][nOnes];
    }
};