class Solution {
public:
    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(i == nums1.size() || j == nums2.size())  return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int count = 0;
        if(nums1[i] == nums2[j])
            count = 1 + helper(i+1, j+1, nums1, nums2, dp);
        else 
            count = max(helper(i+1, j, nums1, nums2, dp), helper(i, j+1, nums1, nums2, dp));
        
        return dp[i][j] = count;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return helper(0, 0, nums1, nums2, dp);
    }
};