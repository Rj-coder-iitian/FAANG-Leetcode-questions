class Solution {
public:
    int countTriples(int n) {
        int sq[n];
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            mp[i*i] = i;
        }
        
        int count = 0;
        for(int c = n;c>1;c--){
            for(int a=1;a<c;a++){
                if(mp.find(c*c - a*a) != mp.end())
                    count++;
            }    
        }
        return count;
    }
};
