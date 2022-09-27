class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
	
		int n = heights.size();
		if (!n) return 0;
        
        heights.push_back(0);
        stack<int>stk;
		int res = 0;
		
		for (int i = 0; i < heights.size(); i++) {
			while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                int l = stk.empty() ? 0 : stk.top()+1;
                res = max(res, (i-l)*h);
			}
			stk.push(i);
		}
        
		return res;
    }
};