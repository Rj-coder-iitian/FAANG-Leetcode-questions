/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root->val == p->val || root->val == q->val)
            return root;
        TreeNode* lCommon = lowestCommonAncestor(root->left, p, q);
        TreeNode* rCommon = lowestCommonAncestor(root->right, p, q);
        if(lCommon && !rCommon)
            return lCommon;
        if(rCommon && !lCommon)
            return rCommon;
        if(lCommon && rCommon)
            return root;
        
        return NULL;
    }
};