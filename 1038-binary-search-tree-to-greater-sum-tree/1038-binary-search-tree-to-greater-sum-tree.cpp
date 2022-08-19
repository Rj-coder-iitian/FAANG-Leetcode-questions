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
    void dfs(TreeNode* root, vector<TreeNode*>& vec) {
        if(!root)
            return;
        dfs(root->left, vec);
        vec.push_back(root);
        dfs(root->right, vec);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> vec;
        dfs(root, vec);
        int n =  vec.size();
        int sum = 0;
        for(int i=n-1;i>=0;i--) {
            sum += vec[i]->val;
            vec[i]->val = sum;
        }
        return root;
    }
};