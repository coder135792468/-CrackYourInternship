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
};