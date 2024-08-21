class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int len = nums.size();
        stack<int> st;
        for(auto ele:nums){
            while(!st.empty() and ele < st.top() and len > k){
                st.pop();
                --len;
            };
            st.push(ele);
        };
        while(st.size() > k)st.pop();
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        };
        reverse(res.begin(),res.end());
        return res;
    }
};