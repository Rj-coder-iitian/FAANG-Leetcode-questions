bool criteria(vector<int> &k, vector<int> &l){
    int m= min(-l[0],-l[0]+l[1]-k[0]);
    int n= min(-k[0],-k[0]+k[1]-l[0]);
    return (n<m || (n==m && k[0]>l[0]));
}

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& trade) {
        sort(trade.begin(), trade.end(), criteria);
        
        long long res = LLONG_MAX;
        long long temp= 0;
        int sz = trade.size();
        for(int i=0; i<sz; i++){
            temp = temp - (long long)trade[i][0];
            res = min(res,temp);
            temp += (long long)trade[i][1];
        }
        return -res;
    }
};
