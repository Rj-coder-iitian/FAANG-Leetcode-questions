class Solution:
    # @return a boolean
    def isInterleaveHelper(self, s1, s1Index, s2, s2Index, s3, s3Index,
                           accessed):
        if (s1Index, s2Index) in accessed:
            # Have tried. Did not success. Wont success.
            return False
        else:
            accessed.add((s1Index, s2Index))
        # Checked all contents in s3. s3 is formed by the interleaving of
        # s1 and s2
        if s3Index == len(s3):
            return True
        # Try to use the next character in s1
        if s1Index != len(s1) and s1[s1Index] == s3[s3Index]:
            if self.isInterleaveHelper(s1, s1Index+1, s2, s2Index, s3,
                                       s3Index+1, accessed):
                return True
        # Try to use the next character in s2
        if s2Index != len(s2) and s2[s2Index] == s3[s3Index]:
            if self.isInterleaveHelper(s1, s1Index, s2, s2Index+1, s3,
                                       s3Index+1, accessed):
                return True
        return False
    # @return a boolean
    def isInterleave(self, s1, s2, s3):
        # Check length firstly.
        if len(s1) + len(s2) != len(s3):
            return False
        # Then check the character count.
        charDis = {}
        for item in s1:     charDis[item] = charDis.get(item, 0) + 1
        for item in s2:     charDis[item] = charDis.get(item, 0) + 1
        for item in s3:     charDis[item] = charDis.get(item, 0) - 1
        for item in charDis:
            if charDis[item] != 0:              return False
        # Finally check overleaving
        return self.isInterleaveHelper(s1, 0, s2, 0, s3, 0, set())
