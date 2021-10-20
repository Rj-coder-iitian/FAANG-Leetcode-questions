class Solution {
public:
    
    void mark(vector<vector<char>>& a, int i, int j){
        int m = a.size(), n= a[0].size();
        if(i<m && i>=0 && j>=0 && j<n && a[i][j]=='O'){
            a[i][j]='*';
            mark(a,i-1,j);
            mark(a,i+1,j);
            mark(a,i,j-1);
            mark(a,i,j+1);
        }
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n= board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j]=='O'){
                        mark(board, i,j);
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(board[i][j]=='*')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
    }
};
