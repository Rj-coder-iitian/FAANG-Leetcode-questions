class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int x = entrance[0];
        int y = entrance[1];
        int M = maze.size();
        int N = maze[0].size();
        if(maze[x][y] == '+')
            return -1;
        int *dist = new int[M*N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
 
            // Assign values to
            // the memory block
            *(dist + i * N + j) = INT_MAX;
            }
        }
        // vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
        queue<pair<int,int>> q;
        q.push({x, y});
        *(dist + x * N + y) = 0;
        // dist[x][y] = 0;
        vector<pair<int,int>> moves = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!q.empty()){
            auto curr = q.front();
            int curX = curr.first;
            int curY = curr.second;
            q.pop();
            for(auto move: moves){
                int xi = curX + move.first;
                int yi = curY + move.second;
            if( xi >= 0 && xi < M && yi >= 0 && yi < N && maze[xi][yi] == '.' && ((*(dist + xi * N + yi)) > (*(dist + curX * N + curY) + 1)))                   {
                    (*(dist + xi * N + yi)) = (*(dist + curX * N + curY) + 1);
                    q.push({xi, yi});
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if((i == 0 || i == M-1 || j == 0 || j == N-1) && !(i == x && j == y)){
                    ans = min(ans,(*(dist + i * N + j)));
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
