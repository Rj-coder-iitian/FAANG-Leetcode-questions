class Solution {
public:
    void helper(vector<vector<int>>& res,vector<int> temp,vector<int>& candidates,int target,int begin){
        if(target < 0)
            return;
        else if(target == 0){
            res.push_back(temp);
            return;
        }else {
            for(int i=begin;i<candidates.size();i++){
                if(i > begin && candidates[i] == candidates[i-1])   continue;
                temp.push_back(candidates[i]);
                helper(res, temp, candidates, target - candidates[i], i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(res, temp, candidates, target, 0);
        return res;
    }
};