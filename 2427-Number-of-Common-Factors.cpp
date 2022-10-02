class Solution {
public:
    int commonFactors(int a, int b) {
        int cnt = 0;
        int n = min(a, b);
        for(int i=1;i<=a;i++){
            if(a%i == 0 && b%i == 0)
                cnt++;
        }
        return cnt;
    }
};
