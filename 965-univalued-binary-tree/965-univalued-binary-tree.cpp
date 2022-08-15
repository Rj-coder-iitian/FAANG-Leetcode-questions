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
    bool isUnivalTreeHelper(TreeNode* root, int val) {
        if(!root)
            return true;
        return (root->val == val) && isUnivalTreeHelper(root->left, val) && isUnivalTreeHelper(root->right, val);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return false;
        int val = root->val;
        return isUnivalTreeHelper(root, val);
    }
};