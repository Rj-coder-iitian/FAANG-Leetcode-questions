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
    void getMinimumDifferenceHelper(TreeNode* root, int& mn, int& prev) {
        if(!root)
            return;
        getMinimumDifferenceHelper(root->left, mn, prev);
        int val = root->val - prev;
        mn = min(mn, val);
        prev = root->val;
        getMinimumDifferenceHelper(root->right, mn, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int mn = INT_MAX;
        int prev = INT_MIN/2;
        getMinimumDifferenceHelper(root, mn, prev);
        return mn;
    }
};