class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        int q= queries.size();
        vector<string> res;
        int d = dict.size();
        int n = queries[0].length();
        for(int i=0;i<q;i++){
            bool flag = false;
            for(int j=0;j<d;j++){
                int matches = 0;
                for(int k=0;k<n;k++){
                    if(queries[i][k] == dict[j][k])
                        matches++;
                }
                if(matches >= n-2){
                    flag = true;
                    break;
                }
            }
            if(flag)
                res.push_back(queries[i]);
        }
        return res;
    }
};
