class Solution {
public:
    string helper(string ans, unordered_set<string> st) {
        int n = ans.length();
        for(int i=0;i<n;i++) {
            if(st.find(ans) == st.end())
                return ans;
            for(int j=i+1;j<n;j++){
                ans[j] = '1';
                if(st.find(ans) == st.end())
                    return ans;
                ans[j] = '0';
            }
            ans[i] = '1';
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st;
        for(auto n : nums)
            st.insert(n);
        string ans = "";
        for(int i=0;i<n;i++){
            ans += "0";
        }
        return helper(ans, st);
    }
};