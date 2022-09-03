class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};


// class Solution {
// public:
//     void backtrack(vector<vector<int>>& res, vector<int> temp, vector<int>& nums,unordered_set<int>& st){
//         if(temp.size() == nums.size()){
//             res.push_back(temp);
//             return;
//         }else {
//             for(int i=0;i<nums.size();i++){
//                 if(st.count(nums[i]))   continue;
//                 temp.push_back(nums[i]);
//                 st.insert(nums[i]);
//                 backtrack(res, temp, nums, st);
//                 temp.pop_back();
//                 st.erase(nums[i]);
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         if(nums.empty())   return {};
//         vector<vector<int>>res;
//         vector<int> cur;
//         unordered_set<int> st;
//         backtrack(res, cur, nums, st);
//         sort(res.begin(), res.end());
//         return res;
//     }
// };