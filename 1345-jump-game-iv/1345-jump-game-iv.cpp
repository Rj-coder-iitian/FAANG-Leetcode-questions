class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        queue<int> q; q.push(0);
        vector<bool> vis(n, false);
        vis[0] = true;
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int cur = q.front();
                q.pop();
                if(cur == n-1)
                    return level;
                vector<int>& next = mp[arr[cur]];
                next.push_back(cur - 1); next.push_back(cur + 1);
                for (int j : next) {
                    if (j >= 0 && j < n && !vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
                next.clear(); // avoid later lookup mp arr[i]
            }
            level++;
        }
        return 0;
    }
};