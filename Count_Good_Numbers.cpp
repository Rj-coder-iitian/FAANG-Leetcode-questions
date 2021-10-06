class Solution {
    #define mod 1000000007
    #define ll long long int
public:
    ll power(ll a, ll b){
        ll res = 1;
        a = a % mod;
        
        while(b > 0){
            if(b & 1)
                res = (res * a) % mod;
            b = b >> 1;
            a = (a * a) % mod;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        ll res = (power(5,n-n/2) * power(4,n/2)) % mod;
        return res;
    }
};
