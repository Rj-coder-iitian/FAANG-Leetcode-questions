class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        int mid= (high+low)/2;
        while(low<=high){
            mid=(high+low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            
        }
        return -1;
    }
};
