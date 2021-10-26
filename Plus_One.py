# problem : Plus One
# hacktoberfest 2021

class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        digits[-1] += 1     # Plus one to the number
        # Normalize the list
        carry = 0
        for index in xrange(len(digits)-1, -1, -1):
            digits[index] += carry
            carry = digits[index] // 10
            # If no carry in this position, no carry any further.
            if carry == 0:      break
            else:               digits[index] %= 10
        else:
            # There is a carry in the most significant digit
            digits.insert(0, 1)
        return digits
