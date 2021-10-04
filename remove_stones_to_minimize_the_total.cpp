int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        for(int i=0;i<k;i++){
            int num = pq.top();
            pq.pop();
            num = num - (num/2);
            pq.push(num);
        }
        int sum = 0;
        while(!pq.empty()){
            int num = pq.top();
            pq.pop();
            sum += num;
        }
        return sum;
    }
