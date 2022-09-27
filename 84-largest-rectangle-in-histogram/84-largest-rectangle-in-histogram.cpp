class Solution {
public:
    vector<int> nextSmallerRight(vector<int>& heights, int n) {
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                res[i] = -1;
            else 
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    
    vector<int> nextSmallerLeft(vector<int>& heights, int n) {
        vector<int> res(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                res[i] = -1;
            else 
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller = nextSmallerLeft(heights, n);
        vector<int> rightSmaller = nextSmallerRight(heights, n);
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            int left = leftSmaller[i];
            int right = rightSmaller[i];
            if(left == -1) left = -1;
            if(right == -1) right = n;
            
            int w = (right - 1) - (left + 1) + 1;
            res = max(res, heights[i]*w);
        }
        return res;
    }
};