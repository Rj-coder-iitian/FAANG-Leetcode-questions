class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        for(int i=2;i<n;i++){
            int max=0;
            for(int j=0;j<i-1;j++){
                if(nums[j]>max)
                    max=nums[j];
            }
            nums[i]+=max;
        }
        int max_sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>max_sum)
                max_sum=nums[i];
        }
        return max_sum;
    }
};
