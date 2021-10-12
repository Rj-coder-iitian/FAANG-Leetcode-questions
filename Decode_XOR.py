#Decode_XOR

class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        results = []
        results.append(first)
        
        i = 0
        for e in encoded:
            reverse_xor = e ^ results[i]            
            results.append(reverse_xor)
            i += 1
        
        return results
