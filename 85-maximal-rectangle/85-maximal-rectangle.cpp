class Solution {
public:
    
    int largestRectangleArea(vector<int> heights) {
        int n = heights.size();
        if(!n)  return 0;
        heights.push_back(0);
        stack<int> st;
        int res = 0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()];
                st.pop();
                int l = st.empty() ? 0 : st.top()+1;
                res = max(res, (i-l)*h);
            }
            st.push(i);
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mat(m, vector<int> (n));
        for(int j=0;j<n;j++){
            mat[0][j] = matrix[0][j] - '0';
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mat[i][j] = matrix[i][j] - '0';
                int val = mat[i][j] == 0 ? 0 : mat[i-1][j];
                mat[i][j] += val;
            }
        }
        int res = INT_MIN;
        for(int i=0;i<mat.size();i++){
            int cur_ar = largestRectangleArea(mat[i]);
            res = max(res, cur_ar);
        }
        return res;
    }
};