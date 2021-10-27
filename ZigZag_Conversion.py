# Problem : ZigZag_Conversion
# Hacktoberfest 2021

class Solution:
    # @return a string
    def convert(self, s, nRows):
        assert nRows > 0        # Must be a non-negative number
        # Handle a specific case, nRows be 1.
        # In such case, the input and output should be the same.
        if nRows == 1:                      return s
        # cache[i] stores the characters in the (i+1)th row,
        # in their original order.
        cache = [[] for _ in xrange(nRows)]
        position = 0    # The index of current row in cache.
        direction = +1  # The direction to find the next row.
        for element in s:
            cache[position].append(element)
            # If we are in the first row, we should find the next
            # row in an increasing order
            if position == 0:               direction = +1
            # If we are in the last row, we should find the next
            # row in a decreasing order
            elif position == nRows - 1:     direction = -1
            position += direction
        return "".join(["".join(row) for row in cache])
