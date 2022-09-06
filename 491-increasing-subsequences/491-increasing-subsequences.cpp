class Solution {
public:
    void helper(set<vector<int>>& res, vector<int>& nums, vector<int> temp, int begin) {
        if(begin > nums.size())
            return;
        if(temp.size() >1)
            res.insert(temp);
        int m = temp.size();
        for(int i=begin;i<nums.size();i++){
            if(m > 0 && nums[i] < temp[m-1]) continue;
            temp.push_back(nums[i]);
            helper(res, nums, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        // vector<bool> vis(n, false);
        helper(res, nums, temp, 0);
        vector<vector<int>> ans;
        for(auto v: res)
            ans.push_back(v);
        return ans;
    }
};