class Solution {
public:
    void dfsHelper(vector<string>& res, string s, int begin){
        if(begin > s.length())
            return;
        if(begin == s.length())
            res.push_back(s);
        int i = begin;
        char c = s[i];
        if(c >= 'a' && c <= 'z'){
            s[i] = c - 'a' + 'A';
            dfsHelper(res, s, i+1);
            s[i] = c;
        } else if(c >= 'A' && c <= 'Z'){
            s[i] = c - 'A' + 'a';
            dfsHelper(res, s, i+1);
            s[i] = c;
        }
        dfsHelper(res, s, i+1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        dfsHelper(res, s, 0);
        return res;
    }
};