class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        char2int = {".":0, "1":1, "2":2, "3":4, "4":8, "5":16, "6":32, "7":64, "8":128, "9":256}
        board = [[char2int[item] for item in line] for line in board]
        # Check each row
        for i in xrange(9):
            sum  = 0
            for value in board[i]:
                if sum & value != 0:                return False
                sum = sum | value
        # Check each column
        for i in xrange(9):
            sum = 0
            for row in xrange(9):
                if sum & board[row][i] != 0:     return False
                sum = sum | board[row][i]
        # Check each block
        for iBlock in xrange(3):
            for jBlock in xrange(3):
                sum = 0
                for i in xrange(3):
                    for j in xrange(3):
                        if sum & board[iBlock*3+i][jBlock*3+j] != 0:    return False
                        sum = sum | board[iBlock*3+i][jBlock*3+j]
        return True
