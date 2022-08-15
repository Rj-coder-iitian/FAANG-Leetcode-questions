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
    int result = 0;
    int dfs(TreeNode* root) {
        int left = (root->left ? dfs(root->left): 0);
        int right = (root->right ? dfs(root->right): 0);
        result += abs(left - right);
        
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        if(root)
            dfs(root);
        return result;
    }
};