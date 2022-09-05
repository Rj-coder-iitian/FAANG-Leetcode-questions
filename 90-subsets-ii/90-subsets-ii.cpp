class Solution {
public:
    void generate_subsets(vector<vector<int>>& res, vector<int> temp, vector<int>& nums, int begin){
        res.push_back(temp);
        for(int i=begin;i<nums.size();i++) {
            if(i > begin && nums[i] == nums[i-1])   continue;
            temp.push_back(nums[i]);
            generate_subsets(res, temp, nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        generate_subsets(res, temp, nums, 0);
        return res;
    }
};