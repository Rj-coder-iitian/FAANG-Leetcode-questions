class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for(auto c: s)
            mp[c]++;
        for(auto c: t) {
            if(mp.find(c) == mp.end())
                return c;
            mp[c]--;
            if(mp[c] == 0)
                mp.erase(c);
        }
        return 'a';
    }
};