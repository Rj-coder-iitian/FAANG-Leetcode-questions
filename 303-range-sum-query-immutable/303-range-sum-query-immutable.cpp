class NumArray {
public:
    vector<int> seg;
    int n;
    void build(int ind, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    int query(int ind, int low, int high, int l, int r) {
        //no overlap
        //l r low high || low high l r
        if(r < low || l > high) {
            return 0;
        }
        //complete overlap
        //{l low high r}
        if(low >= l && high <= r) {
            return seg[ind];
        }
        int mid = (low + high) >> 1;
        int left = query(2*ind + 1, low, mid, l, r);
        int right = query(2*ind + 2, mid + 1, high, l, r);
        return left + right;
    }
    void update(int ind, int low, int high, int i, int val) {
        if(low == high){
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if(i <= mid) {
            update(2*ind + 1, low, mid, i, val);
        } else {
            update(2*ind + 2, mid + 1, high, i, val);
        }
        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.reserve(4 * n + 1);
        build(0, 0, n-1, nums);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */