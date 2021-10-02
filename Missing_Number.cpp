class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Simple mathemetical Sum approach
        // int n=nums.size();
        // int expectedSum=(n*(n+1))/2;
        // int actualSum=0;
        // for(int i=0;i<n;i++){
        //     actualSum+=nums[i];
        // }
        // return expectedSum-actualSum;
        //XOR approach
        int missing=nums.size();
        for(int i=0;i<nums.size();i++){
            missing^=i^nums[i];
        }
        return missing;
    }
};
