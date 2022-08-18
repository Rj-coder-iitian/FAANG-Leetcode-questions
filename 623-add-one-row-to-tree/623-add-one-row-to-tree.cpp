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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while(q.empty() == false) {
            if(count == depth - 1)
                break;
            int n = q.size();
            for(int i=0;i<n;i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            count++;
        }
        while(q.empty() == false) {
            TreeNode* curr = q.front();
            q.pop();
            TreeNode* node1 = new TreeNode(val);
            TreeNode* node2 = new TreeNode(val);
            if(curr->left) {
                node1->left = curr->left;
            }
            curr->left = node1;
            if(curr->right) {
                node2->right = curr->right;
            }
            curr->right = node2;
        }
        return root;
    }
};