#Binary Gap

class Solution:
    def binaryGap(self, n: int) -> int:
        n_bin = bin(n)
        
        longest = 0
        prev = -1
        for i, c in enumerate(n_bin[2:]):
            if c == '1':                
                if prev != -1:
                    distance = i - prev
                    longest = max(distance, longest)
            
                prev = i
                
        
                            
        return longest 
