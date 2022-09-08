class Solution {
public:
    int numTilePossibilities(string tiles) {
        int cnt[26] = {0};
        for(auto s: tiles) cnt[s-'A']++;
        return dfs(cnt);
    }
    int dfs(int cnt[]){
        int sum = 0;
        for(int i=0;i<26;i++){
            if(cnt[i] == 0) continue;
            sum++;
            cnt[i]--;
            sum += dfs(cnt);
            cnt[i]++;
        }
        return sum;
    }
};