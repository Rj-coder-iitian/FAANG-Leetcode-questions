#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
typedef tree<pair<long long int,long long int>, null_type, 
        less<pair<long long int,long long int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set_pair;

typedef long long int ll;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ll sz=nums1.size();
        vector<ll> memo(sz);
        memo[0] = 0ll;
        ordered_set_pair st;
        st.insert({1ll*nums1[0]-1ll*nums2[0],0ll});
        for(int i=1;i<sz;++i){
            long long int x = st.order_of_key({1ll*nums1[i]-1ll*nums2[i] + diff*1ll + 1ll,-1ll});
            memo[i] = memo[i-1] + x;
            st.insert({1ll*nums1[i]-1ll*nums2[i],i*1ll});
        }
        return memo[sz-1];
    }
};
