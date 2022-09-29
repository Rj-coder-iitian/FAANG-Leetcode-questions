class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> hash(n+1, 0);
        for(int i=0;i<n;i++){
            if(citations[i] > n)   hash[n]++;
            else
                hash[citations[i]]++;
        }
        int tot = 0;
        for(int i=n;i>=0;i--){
            tot += hash[i];
            if(tot >= i)    return i;
        }
        return 0;
    }
};