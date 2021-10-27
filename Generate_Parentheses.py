# Problem : Generate Parentheses
# Hacktoberfest 2021

class Solution:
    def _generateParenthesis(self, n, m):
        if n == 0:      return [")"*m]
        elif n == m:    return ["("+i for i in self._generateParenthesis(n-1, m)]
        else:           return ["("+i for i in self._generateParenthesis(n-1, m)] +
                               [")"+i for i in self._generateParenthesis(n, m-1)]
    def generateParenthesis(self, n):
        return self._generateParenthesis(n, n)
