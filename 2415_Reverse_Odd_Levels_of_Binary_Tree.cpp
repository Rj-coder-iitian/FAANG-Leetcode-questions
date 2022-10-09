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
    TreeNode* reverseOddLevels(TreeNode* root, int lvl = 0) {
        if(!root)
            return root;
        if(!root->left && !root->right)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            queue<TreeNode*> change;
            stack<int> vals;
            for(int i=0;i<sz;i++){
                TreeNode* cur = q.front();
                q.pop();
                change.push(cur);
                if(cur->left){
                    q.push(cur->left);
                    vals.push(cur->left->val);
                }
                if(cur->right){
                    q.push(cur->right);
                    vals.push(cur->right->val);
                }
            }
            while((lvl%2 == 0) && (!vals.empty())){
                cout << "lvl even ";
                TreeNode* t = change.front();
                change.pop();
                t->left->val = vals.top();
                vals.pop();
                t->right->val = vals.top();
                vals.pop();
            }
            lvl++;
        }
        return root;
    }
};
