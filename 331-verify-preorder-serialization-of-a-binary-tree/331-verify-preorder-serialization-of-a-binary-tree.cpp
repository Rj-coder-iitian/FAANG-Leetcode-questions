class Solution {
public:
    bool isValidSerialization(string preorder) {
        queue<string> q;
        string s = "";
        for(int i=0;i<preorder.length();i++) {
            if(preorder[i] == ','){
                q.push(s);
                s = "";
                continue;
            }
            s += preorder[i];
        }
        if(s.size() != 0)   q.push(s);
        return isValidSerialization(q);
    }
private:
    bool isValidSerialization(queue<string> q) {
        int count = 1;
        while(q.empty() == false) {
            string cur = q.front();
            q.pop();
            count--;
            if(count < 0)
                return false;
            if(cur != "#")
                count += 2;
        }
        return count == 0;
    }
};