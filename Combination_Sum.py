#Combination Sum

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        results = []
        
        if not candidates:
            return results
        
        candidates = sorted(candidates)
        
        combination = []        
        self.helper(results, candidates, combination, target, 0)
        
        return results
    
    def helper(self, results, candidates, combination, target, start_index):
        if target == 0:            
            results.append(list(combination))            
            return
        
        for i in range(start_index, len(candidates)):
            if candidates[i] > target:
                break
            
            combination.append(candidates[i])
            
            self.helper(results, candidates, combination, target - candidates[i], i)
            
            combination.pop()
