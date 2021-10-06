class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a =target[0], b = target[1], c = target[2];
        int n = triplets.size();
        int c1 =0, c2 = 0, c3 = 0;
        for(int i=0;i<n;i++){
            if((triplets[i][0] == a) && (triplets[i][1] <= b) && (triplets[i][2] <= c)){
                c1 = 1;
            }
            if((triplets[i][0] <= a) && (triplets[i][1] == b) && (triplets[i][2] <= c)){
                c2 = 1;
            }
            if((triplets[i][0] <= a) && (triplets[i][1] <= b) && (triplets[i][2] == c)){
                c3 = 1;
            }
        }
        if(c1 && c2 && c3)
            return true;
        else
            return false;
    }
};
