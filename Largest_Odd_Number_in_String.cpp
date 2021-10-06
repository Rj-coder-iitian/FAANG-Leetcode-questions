class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int i=0;
        for(i=n-1;i>=0;i--){
            char c = num[i];
            int a = c - '0';
            if(a%2){
                break;
            }
        }
        if(i == -1){
            return "";
        }
        string s = num.substr(0,i+1);
        return s;
    }
};
