class Solution {
public:
   set<vector<int>> st;
    void helper(vector<int>& nums, int i,vector<int>& temp){
        st.insert(temp);
        for(int idx = i;idx<nums.size();idx++){
            temp.push_back(nums[idx]);
            helper(nums,idx+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<int> temp;
         helper(nums,0,temp);
         vector<vector<int>> ans;
         for(auto ele:st)ans.push_back(ele);
         return ans;
        
    }
};