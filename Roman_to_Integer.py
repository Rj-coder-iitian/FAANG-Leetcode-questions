# Problem : Roman to Integer
# Hactoberfest 2021

class Solution:
    def romanToInt(self, s):
        transSingleTable = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        transDoubleTable = {"IV":4, "IX":9, "XL":40, "XC":90, "CD":400, "CM":900 }
        result = 0
        index = 0
        roman = s.upper()
        while index < len(s):
            if index < len(s)-1 and roman[index:index+2] in transDoubleTable:
                # Two-letter numeral
                result += transDoubleTable[roman[index:index+2]]
                index += 2
            elif roman[index] in transSingleTable:
                # One-letter numeral
                result += transSingleTable[roman[index]]
                index += 1
            else:
                # Unexpected input
                raise LookupError("Invalid Roman numeral!")
        return result
