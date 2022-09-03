class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int> temp, vector<int>& candidates, int target, int begin){
        if(target < 0)
            return;
        else if(target == 0){
            res.push_back(temp);
            return;
        }else {
            for(int i=begin;i<candidates.size();i++){
                temp.push_back(candidates[i]);
                dfs(res, temp, candidates, target - candidates[i], i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dfs(res, temp, candidates, target, 0);
        return res;
    }
};