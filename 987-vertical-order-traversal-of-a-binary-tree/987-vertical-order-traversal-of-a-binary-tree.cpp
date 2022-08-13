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
    void verticalTraversalHelper(TreeNode* root, map<int, vector<pair<int,int>>>& mp, int r, int c) {
        if(!root)
            return;
        mp[c].push_back(make_pair(r, root->val));
        verticalTraversalHelper(root->left, mp, r+1, c-1);
        verticalTraversalHelper(root->right, mp, r+1, c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int,int>>> mp;
        verticalTraversalHelper(root, mp, 0, 0);
        for(auto v: mp){
            vector<pair<int,int>> vec = v.second;
            sort(vec.begin(), vec.end());
            vector<int> sol;
            for(int i=0;i<vec.size();i++){
                sol.push_back(vec[i].second);
            }
            ans.push_back(sol);
        }
        return ans;
    }
};