class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 1)return 0;
        int num1 = nums[n/2], num2 = nums[n/2 -1];
        int res1 = 0, res2 = 0;
        for(auto ele:nums){
            res1+=abs(ele - num1);
            res2+=abs(ele - num2);
        }
        return min(res1,res2);
    }
};