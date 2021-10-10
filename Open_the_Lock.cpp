class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;
        set<string> v;
        queue<string> q;
        q.push("0000");
        for (int d = 1; !q.empty(); d++) {
            for (int n = q.size(); n > 0; n--) {
                string cur = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    for (int dif = 1; dif <= 9; dif += 8) {
                        string s = cur;
                        s[i] = (s[i] - '0' + dif) % 10 + '0';
                        if (s == target) return d;
                        if (!dead.count(s) && !v.count(s)) q.push(s);
                        v.insert(s);
                    }
                }
            }
        }
        return -1;
    }
};
