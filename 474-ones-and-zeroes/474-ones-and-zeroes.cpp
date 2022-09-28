class Solution {
public:
    int dp[601][101][101] = {};
    int helper(vector<pair<int,int>>& a, int index, int nOnes, int nZeros) {
        int n = a.size();
        if(index == n || (nZeros == 0 && nOnes == 0))   return 0;
        
        if(dp[index][nOnes][nZeros] != -1)
            return dp[index][nOnes][nZeros];
        
        if(a[index].first > nOnes || a[index].second > nZeros)
            return dp[index][nOnes][nZeros] = helper(a, index+1, nOnes, nZeros);
        
        int include = 1 + helper(a, index+1, nOnes - a[index].first, nZeros - a[index].second);
        int exclude = helper(a, index+1, nOnes, nZeros);
        
        return dp[index][nOnes][nZeros] = max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int nZeros, int nOnes) {
        memset(dp, -1, sizeof(dp));
        vector<pair<int,int>> a;
        for(auto i: strs){
            int ones = 0, zeros = 0;
            for(auto j: i)
                (j == '1') ? ones++ : zeros++;
            a.push_back({ones, zeros});
        }
        int ans = helper(a, 0, nOnes, nZeros);
        return ans;
    }
};