class Solution {
typedef pair<int, int> pi;
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<pi> pq;
        for(int i=0;i<stones.size();i++) {
            pq.push(make_pair(stones[i], i));
        }
        while(pq.size() > 1){
            auto [a_num, a_i] = pq.top();
            pq.pop();
            auto [b_num, b_i] = pq.top();
            pq.pop();
            if(a_num == b_num)
                continue;
            if(a_num > b_num){
                pq.push(make_pair(a_num - b_num, a_i));
            }else {
                pq.push(make_pair(b_num - a_num, b_i));
            }
        }
        return pq.size() > 0 ? pq.top().first : 0;
    }
};