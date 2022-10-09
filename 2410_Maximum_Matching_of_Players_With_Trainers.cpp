class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ts=0, ps=0, pe = players.size(), te=trainers.size();
        int cnt = 0;
        for(;ps<pe && ts<te;){
            if(players[ps] <= trainers[ts]){
                ps++;
                ts++;
                cnt++;
            } else{
                ts++;
            }
        }
        return cnt;
    }
};
