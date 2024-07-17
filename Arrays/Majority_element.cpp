class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int cnt = 0,ans = nums[0];
        for(auto ele:nums){
            if(cnt==0){
                ans = ele;
                ++cnt;
            }else if(ele == ans){
                ++cnt;
            }else --cnt;
        };
        return ans;
    }
};