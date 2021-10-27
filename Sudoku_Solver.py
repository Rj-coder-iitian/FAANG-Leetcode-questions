# problem : Sudoku Solver
# hacktoberfest 2021

class Solution:
    class _State(object):
        __slot__ = ("board", "row", "col", "usedRow", "usedCol", "usedBlock")
        def __init__(self, board, row, col, usedRow, usedCol, usedBlock):
            self.board = [line*1 for line in board] 
            self.row = row                          
            self.col = col                          
            self.usedRow = usedRow          
            self.usedCol = usedCol          
            self.usedBlock = usedBlock      
    def solveSudoku(self, board):
        # Convert the input (array of strings) to 2D array of integer
        char2int = {"1":1, "2":2, "3":4, "4":8, "5":16, "6":32, "7":64, "8":128, "9":256}
        boardMatrix = [[char2int.get(item, 0) for item in line] for line in board]
        stack = []
        usedRow, usedCol, usedBlock = [0] * 9, [0] * 9, []
        # Get the initially appeared integers in each row and column
        for i in xrange(9):
            usedRow[i] = sum(boardMatrix[i])
            usedCol[i] = sum([line[i] for line in boardMatrix])
        # Get the initially appeared integers in each block
        for iBlock in xrange(3):
            for jBlock in xrange(3):
                usedBlock.append(0)
                for i in xrange(3):
                    for j in xrange(3):
                        usedBlock[-1] = usedBlock[-1] | boardMatrix[iBlock*3+i][jBlock*3+j]
        stack.append(self._State(boardMatrix, 0, 0, usedRow, usedCol, usedBlock))
        current = None
        # Do a DFS
        while len(stack) != 0:
            current = stack.pop()
            while current.row != 9 and current.board[current.row][current.col] != 0:
                current.col += 1
                if current.col == 9:
                    current.row += 1
                    current.col = 0
            if current.row == 9:                
              break
            for toAdd in char2int.values():
                if toAdd & current.usedRow[current.row] != 0:        continue
                if toAdd & current.usedCol[current.col] != 0:        continue
                if toAdd & current.usedBlock[(current.row//3)*3+current.col//3] != 0: continue
                current.board[current.row][current.col] = toAdd
                newUsedRow = current.usedRow * 1
                newUsedRow[current.row] |= toAdd
                newUsedCol = current.usedCol * 1
                newUsedCol[current.col] |= toAdd
                newUsedBlock = current.usedBlock * 1
                newUsedBlock[(current.row//3)*3+current.col//3] |= toAdd
                stack.append(self._State(current.board, current.row, current.col,
                                         newUsedRow, newUsedCol, newUsedBlock))
        del board[:]
        int2char = {0:".", 1:"1", 2:"2", 4:"3", 8:"4", 16:"5", 32:"6", 64:"7", 128:"8", 256:"9"}
        result = ["".join([int2char[i] for i in line]) for line in current.board]
        for line in result:  board.append(line)
        return
