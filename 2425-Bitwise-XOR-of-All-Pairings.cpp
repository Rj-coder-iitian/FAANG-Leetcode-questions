class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
      int m=nums1.size(),n=nums2.size();
      if(m%2==0 && n%2==0) return 0;
          if(m%2==0 && n%2)
          {
            int res=nums1[0];
            for(int i=1;i<m;i++)
            {
              res^=nums1[i];
            }
            return res;
          }
        
          if(m%2 && (n%2 == 0))
          {
            int res=nums2[0];
            for(int i=1;i<n;i++)
            {
              res^=nums2[i];
            }
            return res;
          }
      
         else
         {
           int res=nums1[0];
            for(int i=1;i<m;i++)
            {
              res^=nums1[i];
            }

           for(int i=0;i<n;i++)
            {
              res^=nums2[i];
            }

            return res;
         }
          return 1;
      
    }
};
