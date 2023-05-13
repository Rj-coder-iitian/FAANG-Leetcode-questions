class Solution {
public:
    #define MOD 1000000007
    #define ll long long
    int countGoodStrings(int low, int high, int zero, int one) {
        ll n = high + 1, res = 0;
        vector<ll> dp(n, 0);
        ll maxi = max(zero, one);
        ll mini = min(zero, one);
        for(ll i=0;i<mini;i++)
            dp[i]=0;
        dp[mini]++; dp[maxi]++;
        for(ll i=mini;i<n;i++){
            if(i+mini < n) dp[i+mini] = (dp[i+mini]%MOD + dp[i]%MOD)%MOD;
            if(i+maxi < n) dp[i+maxi] = (dp[i+maxi]%MOD + dp[i]%MOD)%MOD;
            if(low <= i && i <= high)   
                res = (res%MOD + dp[i])%MOD;
        }
        return res;
    }
};