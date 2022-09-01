class Solution {
public:
    bool canMeasureWater(int x, int y, int t) {
        //Case1: limit bcz of " water contained within one or both buckets by the end."
        if(x+y < t)
            return false;
        //Case2: When we can directly have t
        if(x == t || y == t || x+y == t)
            return true;
        //Case3: Using Bezout's lemma
        return t%GCD(x,y) == 0;
    }
    int GCD(int x, int y){
        while(y!=0){
            int temp = y;
            y = x%y;
            x = temp;
        }
        return x;
    }
};