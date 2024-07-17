class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = nums[0];
        if(jump == 0 and nums.size()>1)return 0;
        jump--;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] > jump)jump = nums[i];
            if(jump== 0 and i != nums.size()-1)return 0;
            --jump;
        }
        return 1;
    }
};