#Decode_String


class Solution:
    def decodeString(self, s: str) -> str:
        if not s:
            return ""
        
        result, position = self.helper(s, 0)
        
        return result
    
    
    def helper(self, s, position):
        result = ""
        
        number = 0
        
        while position < len(s):
            char = s[position]
            
            if char.isdigit():
                number = number * 10 + int(char)
            elif char == '[':
                substring, position = self.helper(s, position + 1)
                result += substring * number
                number = 0
            elif char == ']':
                return result, position
            else:
                result += char
            
            position += 1
                
        return result, position
