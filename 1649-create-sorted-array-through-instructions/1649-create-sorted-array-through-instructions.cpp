class Solution {
public:
    //segment tree array
    int seg[400040];
    int query(int ind, int low, int high, int l, int r) {
        //case 1: No overlap
        if(r < low || high < l) 
            return 0;
        //case 2: Complete overlap
        if(l <= low && high <= r) 
            return seg[ind];
        //case 3: Partial overlap
        int mid = low + (high - low)/2;
        int left = query(2*ind + 1, low, mid, l, r);
        int right = query(2*ind + 2, mid + 1, high, l, r);
        return left + right;
    }
    void update(int ind, int low, int high, int pos) {
        // 1. Base Case - Reached the node where update is required
        if(low == high){
            seg[ind]++;
            return;
        }
        // 2. Intermidiate Node
        int mid = low + (high - low)/2;
        if(pos <= mid)
            update(2*ind + 1, low, mid, pos);
        else 
            update(2*ind + 2, mid + 1, high, pos);
        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    }
    int createSortedArray(vector<int>& instructions) {
        int cost = 0;
        const int MAXN = 1e5 + 1;
        const int MOD = 1e9 + 7;
        for(auto v: instructions) {
            int lessCount = query(0, 0, MAXN, 0, v - 1);
            int greaterCount = query(0, 0, MAXN, v + 1, MAXN);
            update(0, 0, MAXN, v);
            cost = (cost + min(lessCount, greaterCount))%MOD;
        }
        return cost;
    }
};