

class Solution {
public:
    #define MOD (int)(1e9 +7)
    # define Klimit 51
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int row = grid.size(), col = grid[0].size();
        vector<long long> vec(Klimit,0);
        
        vector<vector<vector<long long>>> cnt(row,vector<vector<long long>>(col,vec));
        
        cnt[row-1][col-1][(grid[row-1][col-1])%k]++;
        
        for(int i=row-2; i>=0; i--){
            for(int r=0; r<k; r++){
                cnt[i][col-1][(grid[i][col-1]+r)%k] = (cnt[i+1][col-1][r])%MOD;
                
            }
        }
        for(int j=col-2; j>=0; j--){
            for(int r=0; r<k; r++){
                cnt[row-1][j][(grid[row-1][j]+r)%k] = (cnt[row-1][j+1][r])%MOD;
                
            }
        }
        
        for(int i=row-2; i>=0; i--){
            for(int j=col-2; j>=0; j--){
                for(int r=0; r<k; r++){
                    cnt[i][j][(grid[i][j]+r)%k] = (cnt[i+1][j][r] + cnt[i][j+1][r]) %MOD;
                }
            }
        }
        return cnt[0][0][0];
    }
};
