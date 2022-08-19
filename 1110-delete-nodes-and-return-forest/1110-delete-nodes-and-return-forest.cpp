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
    vector<TreeNode*> result;
    set<int> to_deleteSet;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i: to_delete)
            to_deleteSet.insert(i);
        helper(root, result, to_deleteSet, true);
        return result;
    }
    TreeNode* helper(TreeNode* root, vector<TreeNode*>& result, set<int>& to_deleteSet, bool is_root){
        if(!root)   return NULL;
        bool deleted = to_deleteSet.find(root->val) != to_deleteSet.end();
        if(is_root && !deleted)
            result.push_back(root);
        root->left = helper(root->left, result, to_deleteSet, deleted);
        root->right = helper(root->right, result, to_deleteSet, deleted);
        
        return deleted ? NULL : root;
    }
};