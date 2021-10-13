class Solution {
private:
    int row[9][256], col[9][256], cube[3][3][256];
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(cube,0,sizeof(col));
        
        // hash the already existing cell values
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int d = board[r][c];
                    row[r][d] = 1; col[c][d] = 1; cube[r/3][c/3][d] = 1;
                }
            }
        }
        
        solveSudoku(board, 0, 0);
    }
private:
    bool check(vector<vector<char>>& board, int r, int c, char val)
    {
        if(row[r][val] == 1) return false;
        if(col[c][val] == 1) return false;
        if(cube[r/3][c/3][val] == 1) return false;
        return true;
    }
    bool solveSudoku(vector<vector<char>> &board, int i, int j)
    {
        if(i==9) return true;
        if(j==9) return solveSudoku(board, i+1, 0);
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);
    
        for(char d='1'; d<='9'; d++)
        {
            if(check(board, i, j, d))
            {
                board[i][j] = d;
                row[i][d] = 1; col[j][d] = 1; cube[i/3][j/3][d] = 1;  // hash the digit 'd'
                if(solveSudoku(board, i, j+1)) return true;
                board[i][j] = '.';
                row[i][d] = 0; col[j][d] = 0; cube[i/3][j/3][d] = 0;  // unhash the digit 'd'
            }
        }
    
        return false;
    }
};
