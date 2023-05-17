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
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        ListNode* cur = head;
        while(cur != NULL){
            nums.push_back(cur->val);
            cur = cur->next;
        }
        int n = nums.size(), res = 0;
        for(int i=0;i<n/2;i++){
            res = max(res, nums[i] + nums[n-1-i]);
        }
        return res;
    }
};