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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,pair<int, int>> mp;
        if(!root)
            return false;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int lvl = 0;
        while(q.empty() == false) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                auto it = q.front();
                TreeNode* curr = it.first;
                q.pop();
                mp[curr->val] = make_pair(it.second, lvl);
                if(curr->left)
                    q.push(make_pair(curr->left, curr->val));
                if(curr->right)
                    q.push(make_pair(curr->right, curr->val));
            }
            lvl++;
        }
        return ( mp[x].first != mp[y].first && mp[x].second == mp[y].second);
    }
};