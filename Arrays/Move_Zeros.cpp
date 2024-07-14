class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr1 = -1 ;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0 and ptr1 == -1)ptr1= i;
            else{
                if(nums[i] != 0 and ptr1 == -1)continue;
                if(nums[i] != 0){
                    swap(nums[i],nums[ptr1]);
                    while(nums[ptr1] != 0)++ptr1;
                }
            }
            
        }
        
        
    }
};