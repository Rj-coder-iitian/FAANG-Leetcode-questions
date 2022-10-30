class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        int res = INT_MAX;
        vector<int> rj(n);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            rj[i] = nums[i]%space;
            mp[rj[i]]++;
        }
        int mx = 0;
        for(auto it=mp.begin();it != mp.end(); it++){
            mx = max(mx, it->second);
        }
        set<int> temp_st;
        for(auto it=mp.begin();it != mp.end(); it++){
            if(it->second == mx){
                temp_st.insert(it->first);
            }
        }
        for(int i=0;i<n;i++){
            int m_temp = nums[i]%space;
            if(temp_st.find(m_temp) != temp_st.end())
                res = min(res, nums[i]);
        }
        return res;
    }
};
