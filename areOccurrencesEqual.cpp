class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int count = mp[s[0]];
        for(auto it: mp){
            if(it.second != count)
                return false;
        }
        return true;
    }
};
