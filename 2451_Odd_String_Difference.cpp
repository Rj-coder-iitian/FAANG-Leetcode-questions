class Solution {
public:
    string oddString(vector<string>& words) {
        int m = words.size();
        int n = words[0].size();
        int rj = 0;
        vector<vector<int>> diff(m, vector<int>(n-1));
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                diff[i][j-1] = words[i][j] - words[i][j-1];
            }
        }
        for(;rj<m;rj++){
            int count = 0;
            for(int i=0;i<m;i++){
                if(rj == i)
                    continue;
                bool flag = false;
                for(int j=0;j<n-1;j++){
                    if(diff[i][j] != diff[rj][j]){
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    count++;
            }
            if(count == m-1)
                break;
        }
        return words[rj];
    }
};
