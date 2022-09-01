class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> banks(bank.begin(), bank.end());
        if(!banks.count(end))
            return -1;
        int steps = 0;
        queue<string> q;
        q.push(start);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string cur = q.front();
                q.pop();
                if(cur == end)
                    return steps;
                banks.erase(cur);
                for(int i=0;i<8;i++){
                    string temp = cur;
                    temp[i] = 'A';
                    if(banks.count(temp))   q.push(temp);
                    temp[i] = 'G';
                    if(banks.count(temp))   q.push(temp);
                    temp[i] = 'C';
                    if(banks.count(temp))   q.push(temp);
                    temp[i] = 'T';
                    if(banks.count(temp))   q.push(temp);
                }
            }
            steps++;
        }
        return -1;
    }
};