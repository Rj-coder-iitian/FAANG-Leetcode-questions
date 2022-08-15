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
    void fillParentMap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& mp) {
        if(!node)
            return;
        mp[node] = parent;
        if(node->left)
            fillParentMap(node->left, node, mp);
        if(node->right)
            fillParentMap(node->right, node, mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        unordered_set<TreeNode*> vis;
        fillParentMap(root,NULL, mp);
        vector<int>ans;
        if(!root || !target)
            return ans;
        queue<TreeNode*> q;
        q.push(target);
        int dis = 0;
        while(q.empty() == false) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                TreeNode* curr = q.front();
                q.pop();
                vis.insert(curr);
                if(dis == k)
                    ans.push_back(curr->val);
                if(curr->left && vis.find(curr->left) == vis.end()) {
                    q.push(curr->left);
                }
                if(curr->right && vis.find(curr->right) == vis.end()) {
                    q.push(curr->right);
                }
                if(mp[curr] && vis.find(mp[curr]) == vis.end()) {
                    q.push(mp[curr]);
                }
            }
            dis++;
        }
        return ans;
    }
};