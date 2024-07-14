class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)return 0;
         int start = 0, count = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[start] != nums[i]){
                start++, swap(nums[start],nums[i]), count++;
            }
        };
        return count;
        
    }
};