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
    int maxAncestorDiff(TreeNode* root, int mn=100000, int mx=0) {
        return root ? max(maxAncestorDiff(root->left, min(mn, root->val), max(mx, root->val)), maxAncestorDiff(root->right, min(mn, root->val), max(mx, root->val))) : mx-mn;
    }
};