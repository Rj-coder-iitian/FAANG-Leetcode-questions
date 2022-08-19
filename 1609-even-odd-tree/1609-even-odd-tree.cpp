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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int n = q.size();
            int prev = level%2 ? 1000001 : 0;
            for(int i=0;i<n;i++) {
                TreeNode* curr = q.front();
                q.pop();
                int val = curr->val;
                if((val+level)%2 == 0)
                    return false;
                if(level%2){
                    if(prev <= val)
                        return false;
                } else {
                    if(prev >= val)
                        return false;
                }
                prev = val;
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
            }
            level++;
        }
        return true;
    }
};