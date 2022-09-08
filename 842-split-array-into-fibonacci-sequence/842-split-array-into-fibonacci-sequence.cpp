class Solution {
public:
    vector<int> res;
    void dfsHelper(string s, int begin, vector<int>& temp){
        if(begin == s.size() && temp.size() > 2){
            res = temp;
            return;
        }
        long long num = 0;
        for(int i = begin; i < s.length();i++){
            num = num*10 + s[i] - '0';
            if(num > INT_MAX)   return;
            if(s[begin] == '0' && i > begin)    return;
            if(temp.size() < 2 || num == (long long)temp.back() + (long long)temp[temp.size()-2]){
                temp.push_back(num);
                dfsHelper(s, i+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<int> splitIntoFibonacci(string s) {
        vector<int> temp;
        dfsHelper(s, 0, temp);
        return res;
    }
};