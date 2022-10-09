class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) 
    {
      int sz=nums.size();
      vector<int> res(sz,0);
        for(int i=0;i<sz;i++){
            res[i] = 1;
        }
      vector<int> bit(30,0);
      for(int i=sz-1;i>=0;i--)
      {
        int mx=0;
        for(int j=0;j<30;j++)
        {
          if(((1<<j) & nums[i])==0)
            mx=max(mx,bit[j]);
          res[i]=max(mx-i+1,1); 
        }
        
        for(int j=0;j<30;j++)
        {
          if((1<<j) & nums[i])
            bit[j]=i;
        }
      }
      return res;
    }
};
