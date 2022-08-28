class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<int, vector<int>> adj;
        int n = watchedVideos.size();
        for(int i=0;i<n;i++)
            for(auto num : friends[i])
                adj[i].push_back(num);
        
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(id);
        vis[id] = true;
        int cnt = 0;
        while(!q.empty() && cnt < level){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int cur = q.front();
                q.pop();
                for(auto v: adj[cur]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            cnt++;
        }
        unordered_map<string, int> smp;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i=0;i<watchedVideos[cur].size();i++){
                smp[watchedVideos[cur][i]]++;
                cout << watchedVideos[cur][i] << " ";
            }
        }
        map<int, vector<string>> resMp;
        for(auto it: smp){
            resMp[it.second].push_back(it.first);
        }
        vector<string> ans;
        for(auto it: resMp){
            sort(it.second.begin(), it.second.end());
            for(int i=0;i<it.second.size();i++)
                ans.push_back(it.second[i]);
        }
        return ans;
    }
};