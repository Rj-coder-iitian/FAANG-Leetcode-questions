typedef pair<int, int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> graph(n+1);
        for(const auto& t: times) {
            graph[t[0]].push_back(make_pair(t[1], t[2]));
        }
        vector<int> dist(n+1, INT_MAX);
        vector<bool> vis(n+1, false);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[k] = 0;
        pq.push({0, k});
        int u, v, w;
        while(!pq.empty()){
            u = pq.top().second; pq.pop();
            if(vis[u])  continue;
            vis[u] = true;
            for(auto& to: graph[u]){
                v = to.first, w = to.second;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        int res = 0;
        for(int i=1;i<=n;i++){
            res = max(res, dist[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};