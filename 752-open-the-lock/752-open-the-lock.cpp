class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end()), vis({"0000"});
        if(deads.find("0000") != deads.end())   return -1;
        if(target == "0000")    return 0;
        queue<string> q;
        q.push("0000");
        int turns = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string cur = q.front();
                q.pop();
                if(cur == target)   
                    return turns;
                for(int i=0;i<4;i++){
                    vector<string> temp = rotate(cur, i);
                    if(deads.find(temp[0]) == deads.end() && vis.find(temp[0]) == vis.end()){
                        vis.insert(temp[0]);
                        q.push(temp[0]);
                    }
                    if(deads.find(temp[1]) == deads.end() && vis.find(temp[1]) == vis.end()){
                        vis.insert(temp[1]);
                        q.push(temp[1]);
                    }
                }
            }
            turns++;
        }
        return -1;
    }
    vector<string> rotate(string s, int i) {
        vector<string> res(2,s);
        res[0][i] = '0' + (res[0][i] - '0' + 1)%10; // forward rotation
        res[1][i] = '0' + (res[1][i] - '0' - 1 +10)%10; //backward rotation
        return res;
    }
};