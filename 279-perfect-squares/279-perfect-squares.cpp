class Solution {
public:
    int numSquares(int n) {
        if(n <= 0)
            return 0;
        
        vector<int> perfectSq(n+1, INT_MAX);
        perfectSq[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j = 1;j*j <=i;j++) {
                perfectSq[i] = min(perfectSq[i], perfectSq[i - j*j] + 1);
            }
        }
        return perfectSq[n];
    }
};