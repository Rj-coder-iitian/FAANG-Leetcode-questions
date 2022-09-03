class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        helper(res, temp, s);
        return res;
    }
    
    void helper(vector<vector<string>>& res, vector<string> temp, string s){
        if(!s.length()){
            res.push_back(temp);
            return;
        }
        for(int i=1;i<=s.length();i++){
            string word = s.substr(0, i);
            if(!isPalindrome(word)) continue;
            temp.push_back(word);
            helper(res, temp, s.substr(i));
            temp.pop_back();
        }
    }
    
    bool isPalindrome(string s){
        int left = 0, right = s.length() - 1;
        while(left <= right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};