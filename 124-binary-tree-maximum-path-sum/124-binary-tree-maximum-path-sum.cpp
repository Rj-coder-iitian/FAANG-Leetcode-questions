/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSumFromDown(TreeNode* root, int& ans){
        if(!root)
            return 0;
        int lSum = maxPathSumFromDown(root->left, ans);
        int rSum = maxPathSumFromDown(root->right, ans);
        ans = max(ans, max(lSum + rSum + root->val, max(lSum + root->val,rSum + root->val)));
        ans = max(ans, root->val);
        return max(max(lSum, rSum) + root->val, root->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSumFromDown(root, ans);
        return ans;
    }
};