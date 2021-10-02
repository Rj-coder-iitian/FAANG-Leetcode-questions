class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> hash;
        for(int i=0;i<s.length();i++)
            hash[s[i]] = i;
        
        int l = 0,r=0;
        vector<int> result;
        while(r < s.length()){
            int curr = hash[s[r++]];
            while(r <= curr and curr < s.length())
            {
                curr = max(curr,hash[s[r]]);
                r++;
            }
            result.push_back(curr-l+1);
            l = r;
        }
        return result;
    }
};
