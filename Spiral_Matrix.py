# problem : Spiral Matrix
# hactoberfest 2021

class Solution:
    def spiralOrder(self, matrix):
        rowLen = len(matrix)
        if rowLen == 0:         return []       # Empty list
        colLen = len(matrix[0])
        result = []
        bound = min(rowLen, colLen)
        for layer in xrange(bound//2):
            # Access the top line
            result.extend(matrix[layer][layer:colLen-layer-1])
            # Access the right line
            result.extend([matrix[i][colLen-layer-1] for i in xrange(layer,rowLen-layer-1)])
            # Access the bottom line
            result.extend(matrix[rowLen-layer-1][colLen-layer-1:layer:-1])
            # Access the left line
            result.extend([matrix[i][layer] for i in xrange(rowLen-layer-1,layer,-1)])
        # Maybe one line is remaining for access
        if bound % 2 == 1:
            if bound == rowLen:
                # The last horizontal line
                result.extend(matrix[bound//2][bound//2:colLen-bound//2])
            else:
                # The last vertical line
                result.extend([matrix[i][bound//2] for i in xrange(bound//2,rowLen-bound//2)])
        return result
