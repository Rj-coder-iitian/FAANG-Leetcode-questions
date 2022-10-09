class Solution {
public:
    int longestContinuousSubstring(string s) {
        int cnt = 1;
        int res = 1;
        for(int i=1;i<s.length();i++){
            int prev = s[i-1] - 'a'; 
            int cur = s[i] - 'a';
            res = max(res, cnt);
            if(cur == prev + 1){
                cnt++;
            } else {
                cnt = 1;
            }
        }res = max(res, cnt);
        return res;
    }
};
