class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> forbi(forbidden.begin(), forbidden.end());
        vector<vector<int>> visited(2, vector<int>(6000));
        queue<pair<int,bool>> q;
        q.push({0, false});
        visited[0][0] = 1;
        visited[1][0] = 1;
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--){
                int cur = q.front().first;
                bool flag = q.front().second;
                q.pop();
                if(cur == x)
                    return ans;
                int forward = cur + a;
                int backward = cur - b;
                if(forward < 6000 && visited[0][forward] == 0 && !forbi.count(forward)) {
                    q.push({forward, false});
                    visited[0][forward] = 1;
                }
                if(backward >= 0 && visited[1][backward] == 0 && !forbi.count(backward) && !flag) {
                    q.push({backward, true});
                    visited[1][backward] = 1;
                }
            }
            ans++;
        }
        return -1;
    }
};