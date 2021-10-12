class Solution {
public:
    int reverse(int x) {
  
        string s = to_string(x);
        bool k(0);
        if(s[0] == '-') k=1;
        #include <string.h>
        ::reverse(s.begin()+k,s.end());
        long long y = stoll(s);
        if (y > (1ll<<31)-1 || y < -(1ll<<31)){
            return 0;
        }
        return y;
        
    }
};