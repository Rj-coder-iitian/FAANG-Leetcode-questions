class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                int ind = q.front();
                q.pop();
                visited[ind] = true;
                for(auto v: rooms[ind]){
                    if(!visited[v])
                        q.push(v);
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(!visited[i])
                return false;
        }
        return true;
    }
};