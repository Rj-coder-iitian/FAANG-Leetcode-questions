class Solution {
public:
    int row, col;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(board, i, j, word))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,int i, int j, string word){
        if(!word.size())
            return true;
        if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[0])
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool res = dfs(board, i+1, j, s) || dfs(board, i - 1, j, s) || dfs(board, i, j + 1, s) || dfs(board, i, j - 1, s);
        board[i][j] = c;
        return res;
    }
};