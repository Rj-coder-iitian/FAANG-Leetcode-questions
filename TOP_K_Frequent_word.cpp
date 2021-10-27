typedef pair<int,string> T;
class Solution {
public:
    struct compare
    {
        bool operator()(T a,T b)
        {
            if(a.first == b.first)
                return a.second > b.second;
            else
                return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<T,vector<T>,compare> pq;
        unordered_map<string,int> hash;
        
        for(string word:words)
            hash[word]++;
        
        for(auto ele:hash)
            pq.push({ele.second,ele.first});
        
        vector<string> result;
        
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        //sort(result.begin(),result.end());
        return result;
        
    }
};
