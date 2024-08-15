class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
         vector<int> st, res;
         int n = temp.size();
         for(int i= n-1;i>=0;i--){
            while(!st.empty() and temp[st.back()] <= temp[i])st.pop_back();
            res.push_back(st.empty() ? 0:abs(i - st.back()));
            st.push_back(i);
         }
         reverse(res.begin(),res.end());
         return res;
    }
};