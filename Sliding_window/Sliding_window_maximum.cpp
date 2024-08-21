class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        vector<int> res;
        for(int i= 0;i<nums.size();i++){
            st.insert(nums[i]);
            if(i>=k-1){
                if(i>=k)st.erase(st.find(nums[i-k]));
                res.push_back(*st.rbegin());
            }
        }
        return res;
    }
};