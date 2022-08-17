class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto query: queries)
            ans.push_back(findMatch(query, pattern));
        return ans;
    }
    bool findMatch(string query, string pattern) {
        int i=0;
        for(auto c: query) {
            if(i<pattern.length() && c == pattern[i]) i++;
            else if(c < 'a') return false;
        }
        return i == pattern.length();
    }
};