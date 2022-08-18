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
    void buildMap(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, TreeNode*>& mp) {
        if(!root)
            return;
        mp[root] = prev;
        buildMap(root->left, root, mp);
        buildMap(root->right, root, mp);
    }
    void findLeafs(TreeNode* root, map<int, vector<TreeNode*>>& leafs) {
        if(!root)
            return;
        if(root->left)
            findLeafs(root->left, leafs);
        if(root->right)
            findLeafs(root->right, leafs);
        if(!root->left && !root->right)
            leafs[root->val].push_back(root);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        if(!root)
            return "";
        TreeNode* prev = NULL;
        unordered_map<TreeNode*, TreeNode*> mp;
        buildMap(root, prev, mp);
        map<int, vector<TreeNode*>> leafs;
        findLeafs(root, leafs);
        auto leaf = leafs.begin();
        for(auto l : (*leaf).second) {
            string str = "";
            TreeNode* curr = l;
            while(curr) {
                str += ('a' + curr->val);
                curr = mp[curr];
            }
            ans.push_back(str);
        }
        sort(ans.begin(), ans.end());
        return ans[0];
    }
};