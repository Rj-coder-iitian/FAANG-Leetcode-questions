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
    void buildBSTarr(TreeNode* root, vector<TreeNode*>& vec) {
        if(!root)
            return;
        buildBSTarr(root->left, vec);
        vec.push_back(root);
        buildBSTarr(root->right, vec);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> vec;
        buildBSTarr(root, vec);
        for(int i=0;i<vec.size()-1;i++) {
            vec[i]->left = NULL;
            vec[i]->right = vec[i+1];
        }
        vec[vec.size()-1]->left = NULL;
        vec[vec.size()-1]->right = NULL;
        
        return vec[0];
    }
};