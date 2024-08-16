class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;
        stack<int> st;
        st.push(-1);
        int res= 0;
        for(int i= 0;i<=arr.size();i++){
            while(st.top() != -1 and (i == arr.size() or arr[i] <= arr[st.top()])){
            int ele = st.top();
            st.pop();
            res+=(arr[ele]*(ele - st.top())*(i - ele));
            res%=mod;
            }
            st.push(i);
        }
        return res;
    }
};