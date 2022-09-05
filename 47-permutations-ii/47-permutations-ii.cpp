class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int> temp, vector<int>& nums,vector<bool>& vis){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }else {
            for(int i=0;i<nums.size();i++){
                if(vis[i] || i > 0 && nums[i] == nums[i-1] && !vis[i-1])   continue;
                temp.push_back(nums[i]);
                vis[i] = true;
                backtrack(res, temp, nums, vis);
                temp.pop_back();
                vis[i] = false;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        vector<vector<int>>res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(res, cur, nums, vis);
        return res;
    }
};