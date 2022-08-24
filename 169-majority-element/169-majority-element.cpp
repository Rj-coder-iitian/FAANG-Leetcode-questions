class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        unordered_map<int, int> f;
        for(int i=0;i<n;i++) {
            f[nums[i]]++;
            st.insert(nums[i]);
        }
        for(auto it = st.begin(); it != st.end(); it++) {
            if(f[*it]*2 >= n)
                return *it;
        }
        return nums[0];
    }
};