class Solution {
public:
    static bool sortInCol( const vector<int>& v1, const vector<int>& v2 ) {
    return v1[0] < v2[0];
    }
    int maximumPopulation(vector<vector<int>>& logs) {
        sort(logs.begin(),logs.end(),sortInCol);
        int ans=1,yr=0;
        for(int i=logs.size() - 1;i>=0;i--){
            int temp = 1;
            for(int j = i-1;j>=0;j--){
                if(logs[j][1] > logs[i][0]){
                    temp++;
                }
            }
            if(temp>=ans){
                ans = temp;
                yr = logs[i][0];
            }
        }
        return yr;
    }
};
