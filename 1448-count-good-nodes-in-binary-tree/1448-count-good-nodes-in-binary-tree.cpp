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
    int ans = 0;
    void pre(TreeNode* root, int max) {
        if(!root)
            return;
        if(root->val >= max) {
            ans++;
            max = root->val;
        }
        pre(root->left, max);
        pre(root->right, max);
    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        pre(root, INT_MIN);
        return ans;
    }
};