class Solution {
public:
    int countArrangement(int n) {
        int cnt = 0;
        vector<bool> vis(n, false);
        vector<int> path;
        dfsHelper(path, vis, cnt, n);
        return cnt;
    }
private:
    void dfsHelper(vector<int>& path, vector<bool>& vis, int& cnt, int n)
    {
        if (path.size() == n){
            ++cnt;
            return;
        }
        int pos = path.size() + 1; 
        for (int i = 1; i <= n; ++i)
        {
            if ((i % pos == 0 || pos % i == 0) && !vis[i])
            {
                vis[i] = true;
                path.push_back(i);
                dfsHelper(path, vis, cnt, n);
                vis[i] = false; 
                path.pop_back();
            }
        }
    }
};