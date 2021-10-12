#3sum_closest

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        three_sum_closest = sys.maxsize
        
        nums = sorted(nums)
                
        for i, num in enumerate(nums):        
            l = i + 1
            r = len(nums) - 1
                        
            while l < r:       
                local_sum = nums[i] + nums[l] + nums[r]
                if abs(local_sum - target)  < abs(three_sum_closest - target):
                    three_sum_closest = local_sum
                
                if local_sum <= target:
                    l += 1
                else:
                    r -= 1
        
        return three_sum_closest
