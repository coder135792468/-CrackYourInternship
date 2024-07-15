class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> st;
        for(int i = nums2.size() - 1;i>=0;i--){
            while(!st.empty() and nums2[i] > st.back())st.pop_back();
            mp[nums2[i]] = st.empty()?-1:st.back();
            st.push_back(nums2[i]);
        };
        vector<int> res;
        for(auto ele:nums1){
            res.push_back(mp[ele]);
        }
        return res;
    }
};