class Solution {
public:
    int count =0;
    unordered_set <string> strset;
    map <string, bool> checked;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        if(count==0){
            for(int i=0; i<wordDict.size();i++){
                strset.insert(wordDict[i]);
                count++;
            }
        }
        if(strset.find(s) != strset.end()){
            checked.insert({s, true});
            return true;
        }
        if(checked.find(s) != checked.end()){
            return checked.find(s)->second;
        }
        for(int i=1;i<=s.length();i++){
            string left= s.substr(0,i);
            if(strset.find(left) != strset.end() && wordBreak(s.substr(i, s.length()-i), wordDict)){
                checked.insert({s, true});
                return true;
            }  
        }
        checked.insert({s, false});
        return false;
    }
};
