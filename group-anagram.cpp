class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    vector<vector<string>> ANS;
    string word;
    
    unordered_map<string,vector<string>> um;
    
    for(int i=0; i<strs.size(); i++){
        
        word = strs[i];
        sort(word.begin(),word.end());
        
        um[word].push_back(strs[i]);
    }
    
    for(auto x:um) ANS.push_back(x.second);
    
    return (ANS);
    
	}
};
