/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildBSTFromSortedArray(vector<int>& nums, int is, int ie) {
        if(is > ie)
            return NULL;
        int mid = is + (ie-is)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBSTFromSortedArray(nums, is, mid-1);
        root->right = buildBSTFromSortedArray(nums, mid + 1, ie);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root;
        vector<int> nums;
        ListNode* curr = head;
        while(curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        root = buildBSTFromSortedArray(nums, 0, nums.size()-1);
        return root;
    }
};