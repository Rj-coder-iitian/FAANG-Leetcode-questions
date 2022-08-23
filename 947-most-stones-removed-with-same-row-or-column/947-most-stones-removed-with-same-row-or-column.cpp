class Solution {
public:
    unordered_map<int, int> f;
    int islands = 0;
    int find(int x) {
        if(!f.count(x)) f[x] = x, islands++;
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) f[x]  = y, islands--;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for(int i=0;i<n;i++) {
            uni(stones[i][0], ~stones[i][1]);
        }
        return n - islands;
    }
};