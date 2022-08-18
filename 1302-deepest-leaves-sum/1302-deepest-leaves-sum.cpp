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
    int deepestLeavesSum(TreeNode* root) {
      int ans=root->val;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
        int s=q.size();
        int ans1=0;
        for(int i=0;i<s;i++){
          ans1+=q.front()->val;
          if(q.front()->left) q.push(q.front()->left);
          if(q.front()->right) q.push(q.front()->right);
          q.pop();
        }
        if(q.empty()) ans=ans1;
      }
      return ans;
    }
};