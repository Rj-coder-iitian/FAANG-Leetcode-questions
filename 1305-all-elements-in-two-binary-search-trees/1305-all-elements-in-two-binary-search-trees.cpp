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
    void dfs(TreeNode* root, vector<int>& v) {
        if(!root)
            return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, v;
        dfs(root1, v1);
        dfs(root2, v2);
        int m = v1.size(), i, j;
        int n = v2.size();
        for(i=0,j=0; i<m && j<n;){
            if(v1[i] < v2[j]){
                v.push_back(v1[i++]);
            } else {
                v.push_back(v2[j++]);
            }
        }
        while(i<m)
            v.push_back(v1[i++]);
        while(j<n)
            v.push_back(v2[j++]);
        return v;
    }
};