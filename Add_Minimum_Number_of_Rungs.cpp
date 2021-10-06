class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ini = 0;
        int ans =0;
        for(int i=0;i<rungs.size();i++){
            if(rungs[i]-ini > dist){
                if((rungs[i] - ini)%dist == 0)
                    ans += (rungs[i] - ini)/dist -1;
                else 
                    ans += (rungs[i] - ini)/dist;
            }
            ini = rungs[i];
        }
        return ans;
    }
};
