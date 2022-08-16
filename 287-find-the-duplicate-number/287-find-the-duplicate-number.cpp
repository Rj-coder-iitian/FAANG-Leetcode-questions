class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto n : nums)
            mp[n]++;
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i) != mp.end() && mp[i] > 1)
                return i;
        }
        return 0;
    }
};