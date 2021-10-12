#Container With Most Water


class Solution:
    def maxArea(self, height: List[int]) -> int:        
        max_area = 0
        
        i = 0
        j = len(height) - 1
        
        while i < j:            
            area_width = j - i
            area_height = min(height[i], height[j])
            
            area = area_width * area_height
            
            max_area = max(max_area, area)
        
            if height[i] < height[j]:                
                i += 1
            else:
                j -= 1
                        
        return max_area
