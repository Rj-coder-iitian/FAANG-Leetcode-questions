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
    TreeNode* constructMaximumBinaryTreeHelper(vector<int>& nums, int s, int e) {
        if(s>e) 
            return NULL;
        int mx = -1, loc = -1;
        for(int i=s;i<=e;i++){
            if(nums[i] > mx) {
                mx = nums[i];
                loc = i;
            }
        }
        TreeNode* root = new TreeNode(mx);
        root->left = constructMaximumBinaryTreeHelper(nums, s, loc-1);
        root->right = constructMaximumBinaryTreeHelper(nums, loc + 1, e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = constructMaximumBinaryTreeHelper(nums, 0, nums.size() - 1);
        return root;
    }
};