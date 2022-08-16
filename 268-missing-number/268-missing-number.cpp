class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(auto num : nums)
            st.insert(num);
        for(int i=0;i<=n;i++){
            if(st.find(i) == st.end())
                return i;
        }
        return n;
    }
};