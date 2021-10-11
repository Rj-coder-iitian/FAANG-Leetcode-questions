class Solution:
    def expand(self, s: str) -> List[str]:
        results = []
        
        end = len(s)
        
        self.helper(results, "", 0, s)
        
        results = sorted(results)
        
        return results
                
    def helper(self, results, combination, start, s):        
        if start == len(s):
            results.append(combination)
            return
        
        i = start
        
        if s[i] == '{':
            j = i + 1            
            
            options = []

            while s[j] != '}':
                if s[j] != ',':
                    options.append(s[j])
                j += 1
            
            for option in options:                
                self.helper(results, combination + option, j + 1, s)

        elif s[i] == '}':
            return
        
        else:                
            self.helper(results, combination + s[i], i + 1, s)
