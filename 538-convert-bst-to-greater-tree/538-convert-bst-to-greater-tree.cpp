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
    void convertBSTHelper(TreeNode* root, long long& sum) {
        if(!root)
            return;
        convertBSTHelper(root->right, sum);
        sum += root->val;
        root->val = sum;
        convertBSTHelper(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        long long sum = 0;
        convertBSTHelper(root, sum);
        return root;
    }
};