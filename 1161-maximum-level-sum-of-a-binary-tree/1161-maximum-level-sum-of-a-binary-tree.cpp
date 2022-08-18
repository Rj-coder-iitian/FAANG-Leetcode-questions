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
    int maxLevelSum(TreeNode* root) {
        map<int, vector<int>, greater<int> > mp;
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        while(q.empty() == false) {
            int n = q.size();
            int sum = 0;
            for(int i=0;i<n;i++) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            mp[sum].push_back(lvl++);
        }
        auto it = mp.begin();
        vector<int> v = (*it).second;
        sort(v.begin(), v.end());
        return v[0];
    }
};