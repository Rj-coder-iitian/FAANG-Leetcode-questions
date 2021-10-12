#Maximum Subarray

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        prefix_sum = 0
        max_sum = -sys.maxsize
        min_sum = sys.maxsize
        
        for num in nums:
            prefix_sum += num           
            max_sum = max(max_sum, prefix_sum, prefix_sum - min_sum)
            min_sum = min(min_sum, prefix_sum)
            
        return max_sum
