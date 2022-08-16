class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto n : nums)
            x = x^n;
        return x;
    }
};