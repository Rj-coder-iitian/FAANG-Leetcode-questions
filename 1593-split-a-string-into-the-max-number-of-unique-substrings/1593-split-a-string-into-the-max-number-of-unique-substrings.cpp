class Solution {
public:
    int res = 1;
    void dfsHelper(string s, int start, unordered_set<string>& st) {
        if(start == s.length()){
            int n = st.size();
            res = max(res, n);
            return;
        }
        for(int i=start; i<s.length();i++){
            string temp = s.substr(start, i-start+1);
            if(st.find(temp) != st.end()) continue;
            st.insert(temp);
            dfsHelper(s, i+1, st);
            st.erase(temp);
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        dfsHelper(s, 0, st);
        return res;
    }
};