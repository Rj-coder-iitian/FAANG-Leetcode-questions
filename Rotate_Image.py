#HactoberFest 2021

class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of lists of integers
    def rotate(self, matrix):
        mLen = len(matrix)          # The dimensions of the matrix
        # Determine the block size to rotate
        iLen = mLen // 2
        if mLen % 2 == 0:    jLen = mLen // 2
        else:                jLen = mLen // 2 + 1
        for i in xrange(iLen):
            for j in xrange(jLen):
                # Swap the four elements
                matrix[i][j], matrix[j][mLen-i-1], matrix[mLen-i-1][mLen-j-1], matrix[mLen-j-1][i] =
                    matrix[mLen-j-1][i], matrix[i][j], matrix[j][mLen-i-1], matrix[mLen-i-1][mLen-j-1]
        return matrix
