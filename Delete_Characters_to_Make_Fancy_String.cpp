string makeFancyString(string s) {
        int n = s.length();
        string ans = "";
        unordered_map<char,int> mp;
        for(int i=0;i<n-2;i++){
            if(s[i] == s[i+1] && s[i] == s[i+2]){
                continue;
            }else{
                ans += s[i];
            }
        }
        if(n>2){
            ans += s[n-2];
            ans += s[n-1];
        }else
            return s;
        return ans;
    }
