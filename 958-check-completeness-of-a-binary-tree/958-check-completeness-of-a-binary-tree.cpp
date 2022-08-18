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
    bool isCompleteTree(TreeNode* root) {
        bool flag =  false;
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false) {
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr= q.front();
                q.pop();
                if(!curr) {
                    flag = true;
                } else {
                    if(flag)
                        return false;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return true;
    }
};