class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res = 0;
        for(int i =0;i<=heights.size();i++){
            while(!st.empty() and 
                    (i == size(heights) or heights[st.top()] >= heights[i])){
                int curr = st.top();
                st.pop();
                int w = st.empty()?i:i - st.top() - 1;
                res = max(res,w*heights[curr]);                
            };
            st.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> matrix(n,vector<int>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)matrix[i][j] = grid[i][j] - '0';
        }
        for(int i= 0;i<n;i++){
            for(int j = 0;j<m and i > 0;j++){
                if(matrix[i][j] == 0)continue;
                matrix[i][j]+=matrix[i-1][j];
            }
            res = max(res,largestRectangleArea(matrix[i]));
        }

        return res;
    }
};