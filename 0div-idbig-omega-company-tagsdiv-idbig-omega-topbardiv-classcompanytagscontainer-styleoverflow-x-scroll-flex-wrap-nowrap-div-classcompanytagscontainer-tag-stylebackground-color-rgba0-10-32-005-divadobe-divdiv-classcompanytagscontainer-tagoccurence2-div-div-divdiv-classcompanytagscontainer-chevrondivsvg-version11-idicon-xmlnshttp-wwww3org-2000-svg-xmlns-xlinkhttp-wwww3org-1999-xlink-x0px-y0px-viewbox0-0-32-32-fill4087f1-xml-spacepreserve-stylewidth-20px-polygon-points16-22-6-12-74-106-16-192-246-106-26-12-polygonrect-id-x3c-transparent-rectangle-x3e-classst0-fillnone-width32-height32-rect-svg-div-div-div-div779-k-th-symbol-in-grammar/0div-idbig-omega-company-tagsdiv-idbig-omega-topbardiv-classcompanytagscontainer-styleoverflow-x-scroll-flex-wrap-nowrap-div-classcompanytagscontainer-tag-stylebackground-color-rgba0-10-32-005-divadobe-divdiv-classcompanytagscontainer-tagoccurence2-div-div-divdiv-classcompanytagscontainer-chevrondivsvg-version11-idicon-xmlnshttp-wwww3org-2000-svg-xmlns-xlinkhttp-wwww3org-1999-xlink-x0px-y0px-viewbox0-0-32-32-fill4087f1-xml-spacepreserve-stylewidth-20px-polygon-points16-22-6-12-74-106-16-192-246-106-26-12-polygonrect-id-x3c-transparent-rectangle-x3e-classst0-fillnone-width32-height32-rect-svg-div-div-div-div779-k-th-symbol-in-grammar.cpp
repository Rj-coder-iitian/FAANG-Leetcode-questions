using ll = long long int;
class Solution {
private:
    int helper(int k, ll A, int& flip) {
        if(A == 1)
            return flip%2;
        else{
            A /= 2;
            if(k > A){
                flip++;
                k -= A;
            }
            return helper(k, A, flip);
        }
    }
public:
    int kthGrammar(int n, int k) {
        ll A = pow(2,n-1);
        int flip = 0;
        return helper(k, A, flip);
    }
};