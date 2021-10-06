class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(),ranges.end());
        int check_sum = 0;
        for(int i=left;i <= right; i++){
            for(int v=0;v < ranges.size(); v++){
                if(ranges[v][0] <= i && i <= ranges[v][1]){
                    check_sum++;
                    break;
                }
            }
        }
        if((right - left +1) == check_sum)
            return true;
        else
            return false;
    }
};
