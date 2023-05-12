class Solution {
public:
    
    long long helper(int i, int n, vector<vector<int>>& questions, vector<long long>& dp) {
        if(i >= n)  return 0;
        if(dp[i] != 0) return dp[i];
        long long ans = 0;
        ans = max(questions[i][0]+helper(i+questions[i][1]+1, n, questions, dp), helper(i+1, n, questions, dp));
        return dp[i] = ans;
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);
        return helper(0, n, questions, dp);
    }
};