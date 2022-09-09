class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, 0);
        vector<bool> vis(n+1, false);
        dfsHelper(0, ans, vis, n);
        return ans;
    }
    bool dfsHelper(int index, vector<int>& ans, vector<bool>& vis, int n) {
        if(index == ans.size())
            return true;
        if(ans[index] != 0)
            return dfsHelper(index + 1, ans, vis, n);
        else{
            for(int i = n;i>=1;i--){
                if(vis[i])  continue;
                vis[i] = true;
                ans[index] = i;
                if(i == 1) {
                    if(dfsHelper(index+1, ans, vis, n))return true;
                } else if(index + i < ans.size() && ans[index+i] == 0){
                    ans[index+i] = i;
                    if(dfsHelper(index+1, ans, vis, n))return true;
                    ans[index+i] = 0;
                }
                ans[index] = 0;
                vis[i] = false;
            }
        }
        return false;
    }
};