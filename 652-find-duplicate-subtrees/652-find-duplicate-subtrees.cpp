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
    string serialize(TreeNode* root, unordered_map<string, vector<TreeNode*>>& map){
        if(!root)
            return "";
        string s = "(" + serialize(root->left, map) + to_string(root->val) + serialize(root->right, map) + ")";
        
        map[s].push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        vector<TreeNode*> ans;
        serialize(root, map);
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second.size() > 1) ans.push_back(it->second[0]);
        }
        return ans;
    }
};