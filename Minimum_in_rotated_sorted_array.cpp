class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(mid>start && nums[mid] < nums[mid-1])
                return nums[mid];
            if(mid<end && nums[mid] > nums[mid+1])
                return nums[mid+1];
           
            if(nums[mid] <= nums[end])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return min(nums[0], nums[nums.size() - 1]);
    }
};
