class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        for(int i=0;i<n;i++){
            unordered_map<char, int> mp;
            unordered_map<int, vector<char>> st;
            for(int j = 0;j<n;j++){
                if(j == i)
                    continue;
                mp[word[j]]++;
            }
            for(auto v : mp){
                st[v.second].push_back(v.first);
            }
            if(st.size() == 1)
                return true;
        }
        return false;
    }
};
