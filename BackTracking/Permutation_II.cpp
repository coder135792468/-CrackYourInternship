class Solution {
public:
   set<vector<int>> st;
    void helper(vector<int>& nums,int start){
       if(start == nums.size()){
           st.insert(nums);
           return;
       };
        for(int i = start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            helper(nums,start+1);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(nums,0);
        vector<vector<int>> ans;
        for(auto ele:st){
            ans.push_back(ele);
        }
        return ans;
    }
};