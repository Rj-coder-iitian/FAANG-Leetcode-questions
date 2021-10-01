class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False]*(len(p)+1) for _ in range(len(s)+1)]
        dp[0][0] = True
        for pos in range(1, len(dp[0])):
            if p[pos-1] == '*':
                dp[0][pos] = dp[0][pos-2]
        for row in range(1, len(dp)):
            for col in range(1, len(dp[0])):
                 if s[row-1] == p[col-1] or p[col-1] == '.':
                     dp[row][col] = dp[row-1][col-1]
                 elif p[col-1] == '*':
                     dp[row][col] = dp[row][col-2]
                     if p[col-2]==s[row-1] or p[col-2] == '.':
                        dp[row][col] = dp[row][col] or dp[row-1][col]
        return dp[-1][-1]


obj = Solution()
s, p =input().split()
check = obj.isMatch(s, p)
print(check)
