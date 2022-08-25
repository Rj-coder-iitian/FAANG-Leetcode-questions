class UnionFind {
  public:
    UnionFind(int n) {
        parent.resize(n);
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
    }
    int Find(int x) {
        int temp = x;
        while(temp != parent[temp]){
            temp = parent[temp];
        }
        while(x != temp){
            int next = parent[x];
            parent[x] = temp;
            x = next;
        }
        return temp;
    }
    bool Union(int x, int y) {
        int xx = Find(x);
        int yy = Find(y);
        if(xx == yy) return false;
        parent[xx] = yy;
        return true;
    }
    
  private:
    vector<int> parent;
};
class myComparator {
  public:
    bool operator() (const vector<int>& v1, const vector<int>& v2) {
      return v1[0] > v2[0]; 
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        UnionFind uf(n);
        priority_queue<vector<int>, vector<vector<int>>, myComparator> pq;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                pq.push({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j});
            }
        }
        int count = 0;
        int ans = 0;
        while(count != n-1){
            auto edge = pq.top();
            int x = uf.Find(edge[1]);
            int y = uf.Find(edge[2]);
            if(x != y){
                uf.Union(x, y);
                ans += edge[0];
                count++;
            }
            pq.pop();
        }
        return ans;
    }
};