class Solution {
typedef pair<int, int> pi;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=1;i<n;i++){
            priority_queue<pi, vector<pi>, greater<pi> > pq;
            for(int k=0;k<n;k++){
                pq.push(make_pair(matrix[i-1][k], k));
            }
            for(int j=0;j<n;j++){
                pair<int, int> p = pq.top();
                if(p.second == j){
                    pq.pop();
                    int val = p.first;
                    p = pq.top();
                    pq.push(make_pair(val, j));
                }
                matrix[i][j] += p.first;
                cout << p.first << "  " ;
            }
        }
        int res = INT_MAX;
        for(int j=0;j<n;j++){
            res = min(res, matrix[n-1][j]);
        }
        return res;
    }
};