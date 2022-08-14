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
    int frequentTreeSumFromDown(TreeNode* root, unordered_map<int, int>& mp) {
        if(!root)
            return 0;
        int lSum =0, rSum =0;
        if(root->left)
            lSum = frequentTreeSumFromDown(root->left, mp);
        if(root->right)
            rSum = frequentTreeSumFromDown(root->right, mp);
        int val = lSum + rSum + root->val;
        mp[val]++;
        cout << val << " ";
        return val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        map<int, vector<int>, greater<int>> sol_map;
        frequentTreeSumFromDown(root, mp);
        for(auto it = mp.begin();it != mp.end();it++){
            sol_map[it->second].push_back(it->first);
        }
        auto it = sol_map.begin();
        return it->second;
    }
};