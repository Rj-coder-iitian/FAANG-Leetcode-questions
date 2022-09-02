class Solution {
public:
    int countOnes(int n){
        int res = 0;
        while(n){
            res += n&1;
            n = n >> 1;
        }
        return res;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        int hours = 0, minutes = 0;
        vector<string> ans;
        while(hours != 12){
            int cnt = countOnes(hours) + countOnes(minutes);
            if(cnt == turnedOn) {
                string minStr = "";
                if(minutes < 10)
                    minStr = "0";
                ans.push_back(to_string(hours) + ":" + minStr + to_string(minutes));
            }
            minutes++;
            if(minutes == 60){
                hours++;
                minutes = 0;
            }
        }
        return ans;
    }
};