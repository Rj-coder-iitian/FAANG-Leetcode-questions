class Solution {
public:
    int helperRight(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1, res = -1;
        while (l <= r){
            int m = l + (r-l)/2;
            if(nums[m] < target)
                l = m+1;
            else if(nums[m] > target)
                r = m-1;
            else{
                res = m;
                l = m+1;
            }
        }
        return res;
    }
    int helperLeft(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1, res = -1;
        while (l <= r){
            int m = l + (r-l)/2;
            if(nums[m] < target)
                l = m+1;
            else if(nums[m] > target)
                r = m-1;
            else{
                res = m;
                r = m-1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int l = helperLeft(nums, target);
        int r = helperRight(nums, target);
        ans.push_back(l);
        ans.push_back(r);
        return ans;
    }
};