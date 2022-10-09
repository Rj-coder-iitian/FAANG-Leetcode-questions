class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int prev = 0, mx = 0, ans = 0;
        int size = logs.size();
        vector<int> diff(size);
        for(int i=0;i<size;i++){
            diff[i] = logs[i][1] - prev;
            prev = logs[i][1];
            if(diff[i]  > mx){
                mx = diff[i];
                ans = logs[i][0];
            } else if(diff[i] == mx && logs[i][0] < ans){
                ans = logs[i][0];
            }
        }
        return ans;
    }
};
