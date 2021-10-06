class Solution {
public:
    int sumr(int n){
        int res = 0;
        while(n>0){
            int rem = n%10;
            res += rem;
            n /= 10;
        }
        return res;
    }
    int vecSum(vector<int> vec){
        int n = vec.size();
        int res = 0;
        for(int i=0;i<n;i++){
            int num = vec[i];
            if(num > 9){
                res += (num%10);
                res += (num/10);
            }else
                res += num;
        }
        return res;
    }
    
    int getLucky(string s, int k) {
        int res = 0;
        vector<int> store;
        for(int i=0;i<s.length();i++){
            int num = s[i] - 'a';
            num++;
            store.push_back(num);
            // if(num>9){
            //     res *= 100;
            // }
        }
        res = vecSum(store);
        for(int i=1;i<k;i++){
            res = sumr(res);
        }
        return res;
    }
};
