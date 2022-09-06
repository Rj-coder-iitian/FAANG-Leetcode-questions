class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int> temp, int idx, int k, int n) {
        if(temp.size() == k){
            if(n == 0)
                res.push_back(temp);
            return;
        }else if(temp.size() < k){
            for(int i=idx;i<=9 && i<=9;i++){
                temp.push_back(i);
                helper(res, temp, i+1, k, n-i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, 1, k, n);
        return res;
    }
};