class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return (nums[n-1]*nums[n-2]) - (nums[1]*nums[0]);
    }
};
