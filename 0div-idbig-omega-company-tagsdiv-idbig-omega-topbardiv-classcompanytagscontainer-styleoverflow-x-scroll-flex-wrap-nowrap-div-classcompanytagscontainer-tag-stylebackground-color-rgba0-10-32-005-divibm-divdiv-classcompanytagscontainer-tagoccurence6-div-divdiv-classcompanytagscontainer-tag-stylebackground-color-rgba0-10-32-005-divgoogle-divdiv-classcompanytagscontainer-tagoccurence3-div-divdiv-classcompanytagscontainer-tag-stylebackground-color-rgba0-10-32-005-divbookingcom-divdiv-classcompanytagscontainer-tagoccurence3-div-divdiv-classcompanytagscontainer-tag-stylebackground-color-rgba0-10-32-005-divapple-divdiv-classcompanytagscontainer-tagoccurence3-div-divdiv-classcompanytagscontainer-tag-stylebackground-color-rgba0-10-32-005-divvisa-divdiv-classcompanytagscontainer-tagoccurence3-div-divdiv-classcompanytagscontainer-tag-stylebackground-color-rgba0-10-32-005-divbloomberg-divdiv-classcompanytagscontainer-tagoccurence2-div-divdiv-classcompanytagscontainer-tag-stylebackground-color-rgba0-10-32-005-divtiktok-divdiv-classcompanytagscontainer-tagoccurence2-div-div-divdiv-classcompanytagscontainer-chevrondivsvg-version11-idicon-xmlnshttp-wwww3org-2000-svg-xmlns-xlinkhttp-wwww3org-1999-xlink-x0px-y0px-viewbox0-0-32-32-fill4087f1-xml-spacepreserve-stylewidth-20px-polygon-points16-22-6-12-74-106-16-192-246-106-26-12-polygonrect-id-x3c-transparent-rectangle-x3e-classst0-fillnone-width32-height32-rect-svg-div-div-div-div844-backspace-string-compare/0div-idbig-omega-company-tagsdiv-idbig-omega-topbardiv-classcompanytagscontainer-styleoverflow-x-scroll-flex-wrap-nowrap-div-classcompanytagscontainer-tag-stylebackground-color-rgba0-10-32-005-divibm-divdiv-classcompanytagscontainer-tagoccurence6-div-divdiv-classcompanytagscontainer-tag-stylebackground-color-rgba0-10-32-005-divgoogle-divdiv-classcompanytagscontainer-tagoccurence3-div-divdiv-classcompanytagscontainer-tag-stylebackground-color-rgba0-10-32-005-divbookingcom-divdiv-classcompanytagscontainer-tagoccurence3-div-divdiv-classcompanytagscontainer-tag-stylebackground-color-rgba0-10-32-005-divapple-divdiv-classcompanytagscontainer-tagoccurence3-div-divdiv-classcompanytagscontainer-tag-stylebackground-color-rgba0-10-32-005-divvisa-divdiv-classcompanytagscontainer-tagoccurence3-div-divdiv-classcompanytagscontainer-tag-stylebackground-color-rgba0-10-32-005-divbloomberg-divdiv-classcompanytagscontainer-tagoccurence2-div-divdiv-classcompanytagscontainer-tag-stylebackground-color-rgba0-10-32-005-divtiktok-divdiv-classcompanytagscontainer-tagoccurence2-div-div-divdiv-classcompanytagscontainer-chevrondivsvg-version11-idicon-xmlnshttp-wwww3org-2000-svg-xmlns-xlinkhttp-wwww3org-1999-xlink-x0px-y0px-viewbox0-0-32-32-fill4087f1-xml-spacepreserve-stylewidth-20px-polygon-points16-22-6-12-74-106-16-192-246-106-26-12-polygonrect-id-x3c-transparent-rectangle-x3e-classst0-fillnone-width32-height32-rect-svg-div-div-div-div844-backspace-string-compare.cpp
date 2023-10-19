class Solution {
public:
    string getString(string str) {
        string ans ="";
        int n = str.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(str[i] == '#'){
                if(!st.empty())
                    st.pop();
            } 
            else{
                st.push(str[i]);
            }
        }
        while(!st.empty()){
            char c = st.top();
            st.pop();
            ans += c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        s = getString(s);
        t = getString(t);
        return s == t;
    }
};