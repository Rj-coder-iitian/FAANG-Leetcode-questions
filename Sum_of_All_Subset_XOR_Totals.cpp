class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int len = nums.size();
        // all subsets will be in vector "subsets"
	vector<vector<int>> subsets;
	for (int i = 0; i < pow(2, len); i++) {
		int t = i;
		vector<int> v;
		for (int j = 0; j < len; j++) {
			if (t & 1)
				v.push_back(nums[j]);
			t >>= 1;
		}
		subsets.push_back(v);
	    }
        int long long sum = 0;
        for (const vector<int>& subset: subsets) {
            int tmp = 0;
		    for (const int& value: subset){
                // cout << value << " ";
                tmp = tmp^value;
            }
            sum = sum + tmp;
		    // cout << tmp << " ";
		    // cout << "\n";
	    }
        return sum;
    }
};
