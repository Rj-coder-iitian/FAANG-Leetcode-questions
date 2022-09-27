class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i=1;i<=n;i++){
            for(auto& c: coins){
                if(i - c < 0)
                    break;
                if(dp[i-c] != INT_MAX)
                    dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};