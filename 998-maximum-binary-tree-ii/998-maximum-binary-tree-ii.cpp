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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root && root->val > val){
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
        TreeNode* node = new TreeNode(val);
        node->left = root;
        return node;
    }
    // void insertIntoMaxTreeArr(TreeNode* root, vector<int>& nums) {
    //     if(!root)
    //         return;
    //     insertIntoMaxTreeArr(root->left, nums);
    //     nums.push_back(root->val);
    //     insertIntoMaxTreeArr(root->right, nums);
    // }
    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<TreeNode*> stk;
    //     for(int i=0;i<n;i++){
    //         TreeNode* curr = new TreeNode(nums[i]);
    //         while(!stk.empty() && stk.back()->val < nums[i]) {
    //             curr->left = stk.back();
    //             stk.pop_back();
    //         }
    //         if(!stk.empty()) {
    //             stk.back()->right = curr;
    //         }
    //         stk.push_back(curr);
    //     }
    //     return stk.front();
    // }
    // TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    //     vector<int> nums;
    //     insertIntoMaxTreeArr(root, nums);
    //     nums.push_back(val);
    //     return constructMaximumBinaryTree(nums);
    // }
};