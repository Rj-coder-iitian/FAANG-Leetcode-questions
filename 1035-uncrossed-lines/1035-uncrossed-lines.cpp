class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n < m) return maxUncrossedLines(nums2, nums1);

        vector<int> dp(m + 1);
        for (int i = 1; i <= n; i++) {
            int prev = 0;
            for (int j = 1; j <= m; j++) {
                int curr = dp[j];
                if (nums1[i-1] == nums2[j-1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j-1], curr);
                }
                prev = curr;
            }
        }
        return dp[m];
    }   
};