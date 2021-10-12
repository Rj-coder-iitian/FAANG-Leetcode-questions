class Solution {
public:
    long long countDigitOne(int n) {
        
        long long ans(0);
        for (long long i = 1; i <= n; i *= 10) {
            long long temp = i * 10;
            ans += (n / temp) * i + min(max(n % temp - i + 1, 0ll), i);
        }
        return ans;
        
        
    }
};