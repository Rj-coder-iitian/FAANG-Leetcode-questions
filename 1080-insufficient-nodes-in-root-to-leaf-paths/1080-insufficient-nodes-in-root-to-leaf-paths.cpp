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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(!root)
            return root;
        //Case 1: node is leaf
        if(!root->left && !root->right)
            return root->val < limit ? NULL : root;
        else {
        //Case 2: root is NOT leaf.
            root->left = sufficientSubset(root->left, limit - root->val);
            root->right = sufficientSubset(root->right, limit - root->val);
            if(!root->left && !root->right)
                return NULL;
        }
        return root;
    }
};