#Binary Prefix Divisible By 5

class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        results = []
        
        binary_str = ""
        for num in A:
            binary_str += str(num)
            
            if int(binary_str, 2) % 5 == 0:
                results.append(True)
            else:
                results.append(False)
                
        
        return results
