class Solution {
public:
    string robotWithString(string s) {
        multiset<char>  x;
        int n=s.size();
        for(int i=0;i<n;i++){
            x.insert(s[i]);
        }
        string ans="";
        stack<char>y;
        for(int i=0;i<n;i++){
            char t=*(x.begin());
             while(y.size() && y.top()<=t){
                ans+=y.top();
                y.pop();
            }
            if(s[i]==t){
                ans+=t;
                x.erase(x.find(t));
            }
            else{
                y.push(s[i]);
                x.erase(x.find(s[i]));
            }
        }
        while(y.size() ){
            ans+=y.top();
            y.pop();
        }
        return ans;
    }
};
