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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* prev = NULL;
        unordered_map<TreeNode*, TreeNode*> mp;
        buildMap(root, prev, mp);
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> leafs;
        while(q.empty() == false) {
            int n = q.size();
            vector<TreeNode*> temp;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            leafs = temp;
        }
        unordered_map<TreeNode*, int> countMp;
        for(auto leaf : leafs) {
            TreeNode* curr = leaf;
            while(curr){
                countMp[curr]++;
                curr = mp[curr];
            }
        }
        TreeNode* curr = leafs[0];
        while(curr){
            if(countMp[curr] == leafs.size())
                return curr;
            curr = mp[curr];
        }
        return root;
    }
};