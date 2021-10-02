class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),p,l;
        for(p = n - 2;p >= 0;p--){
            if(nums[p] < nums[p+1]){
                break;
            }
        }
        if(p < 0){
            reverse(nums.begin(), nums.end());
        }else{
            for(l = n-1;l>p;l--){
                if(nums[l] > nums[p]){
                    break;
                }
            }
            swap(nums[p],nums[l]);
            reverse(nums.begin() + p + 1,nums.end());
        }
    }
};
