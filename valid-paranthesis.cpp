class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        while(i < s.length())
        {
            if(!st.empty()){
                if(s[i]==')' and st.top()=='(')
                    st.pop();
                else if(s[i]=='}' and st.top()=='{')
                    st.pop();
                else if(s[i]==']' and st.top()=='[')
                    st.pop();
                else
                    st.push(s[i]);

            }
            else
                st.push(s[i]);
            i++;
        }
        return st.empty();
    }
};
