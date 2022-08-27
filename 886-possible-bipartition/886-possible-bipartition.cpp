class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> colors(n+1,0);
        vector<vector<int>> graph(n+1);
        for(int i=0;i<dislikes.size();i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(colors[i])   continue;
            colors[i] = 1;
            q.push(i);
            while(!q.empty()){
                int temp = q.front();
                for(auto& v: graph[temp]){
                    if(colors[v] == 0){
                        colors[v] = -colors[temp];
                        q.push(v);
                    }else if(colors[v] == colors[temp])
                        return false;
                }
                q.pop();
            }
        }
        return true;
    }
};