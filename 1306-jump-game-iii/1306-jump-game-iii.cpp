class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        queue<int> q;
        vis[start] = true;
        q.push(start);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int cur = q.front();
                q.pop();
                if(!arr[cur])
                    return true;
                int left = cur - arr[cur];
                int right = cur + arr[cur];
                if(left >=0 && left < n && !vis[left]){
                    vis[left] = true;
                    q.push(left);
                }
                if(right >=0 && right < n && !vis[right]){
                    vis[right] = true;
                    q.push(right);
                }
            }
        }
        return false;
    }
};