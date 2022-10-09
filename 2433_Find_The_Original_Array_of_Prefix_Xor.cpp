class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size(), last = 0;
        vector<int> xor_array(n);
        for(int i=0;i<n;i++){
            xor_array[i] = last^pref[i];
            last = pref[i];
        }
        return xor_array;
    }
};
