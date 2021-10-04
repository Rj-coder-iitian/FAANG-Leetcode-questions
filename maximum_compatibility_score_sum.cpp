int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int res = 0;
        sort(mentors.begin(), mentors.end());
        do{
            int curr = 0;
            for(int i=0;i<students.size();i++){
                for(int j=0;j<students[i].size();j++){
                    if(students[i][j] == mentors[i][j])
                        curr++;
                }
            }
            res = max(res, curr);
        }while(next_permutation(mentors.begin(), mentors.end()));
        return res;
    }
