#Subsets

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        results = []
        
        self.helper(results, nums, [], 0)
        
        return results
    
    def helper(self, results, nums, subset, start):
        results.append(list(subset))
        
        
        for i in range(start, len(nums)):
            num = nums[i]
            subset.append(num)
            self.helper(results, nums, subset, i + 1)
            subset.pop()
