class Solution {
public:
    int max_req = 0;
    void helper(vector<vector<int>>& requests, int index, vector<int>& count, int num) {
        if(index == requests.size()){
            for(auto i: count){
                if(i != 0)
                    return;
            }
            max_req = max(max_req, num);
            return;
        }
            //Choose this index
            count[requests[index][0]]--;
            count[requests[index][1]]++;
            helper(requests, index+1, count, num+1);
            count[requests[index][0]]++;
            count[requests[index][1]]--;
            
            //Not choose this index
            helper(requests, index+1, count, num);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> count(n, 0);
        helper(requests, 0, count, 0);
        return max_req;
    }
};