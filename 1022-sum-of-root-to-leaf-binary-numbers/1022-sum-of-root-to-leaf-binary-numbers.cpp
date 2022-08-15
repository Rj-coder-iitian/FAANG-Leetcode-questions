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
    // void buildSumRootToLeaf(TreeNode* root, vector<vector<int>> ans, vector<int> nums)
    int sumRootToLeafHelper(TreeNode* root, int res) {
        if(!root)
            return 0;
        res = (2*res + root->val);
        
        return (root->left == root->right) ? res : sumRootToLeafHelper(root->left, res) + sumRootToLeafHelper(root->right, res);
    }
    int sumRootToLeaf(TreeNode* root) {
        // vector<vector<int>> ans;
        // vector<int> nums;
        // buildSumRootToLeaf(TreeNode* root, ans, nums);
        if(!root)
            return 0;
        return sumRootToLeafHelper(root, 0);
    }
};