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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        unsigned long long ans = 0;
        q.push(make_pair(root, 1));
        while(q.empty() == false){
            int n = q.size();
            unsigned long long first = 0, second = 0;
            for(int i=0;i<n;i++) {
                auto v = q.front();
                q.pop();
                TreeNode* curr = v.first;
                long long dist = v.second;
                if(i == 0)
                    first = dist;
                if(i == n-1)
                    second = dist;
                if(curr->left){
                    q.push(make_pair(curr->left, (unsigned long long)dist * 2));
                }
                if(curr->right){
                    q.push(make_pair(curr->right, (unsigned long long)dist * 2 + 1));
                }
            }
            ans = max(ans, second - first + 1);
        }
        return ans;
    }
};