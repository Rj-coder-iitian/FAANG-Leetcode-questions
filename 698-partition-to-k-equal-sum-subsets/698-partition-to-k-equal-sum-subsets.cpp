class Solution {
public:
        int dp[(1<<16)+2];
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            int n = nums.size(), sum = 0;
            fill(dp, dp+(1<<16)+2, -1);
            dp[0] = 0;
            for (int i = 0; i < n; i++) sum += nums[i];
            if (sum % k) return false;
            int tar = sum/k;

            for (int mask = 0; mask < (1<<n); mask++) {
                if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
                for (int i = 0; i < n; i++) {
                    if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                        dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                    }
                }
            }
            return dp[(1<<n)-1] == 0;
        }
    };
//       bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int sum = 0;
//         for(int num:nums)sum+=num;
//         if(k <= 0 || sum%k != 0)return false;
//         vector<int> visited(nums.size(), 0);
//         return canPartition(nums, visited, 0, k, 0, 0, sum/k);
//     }
    
//     bool canPartition(vector<int>& nums, vector<int>& visited, int start_index, int k, int cur_sum, int cur_num, int target){
//         if(k==1)return true;
//         if(cur_sum == target && cur_num >0 )return canPartition(nums, visited, 0, k-1, 0, 0, target);
//         for(int i = start_index; i<nums.size(); i++){
//             if(!visited[i]){
//                 visited[i] = 1;
//                 if(canPartition(nums, visited, i+1, k, cur_sum + nums[i], cur_num++, target))return true;
//                 visited[i] = 0;
//             }
//         }
//         return false;
//     }
