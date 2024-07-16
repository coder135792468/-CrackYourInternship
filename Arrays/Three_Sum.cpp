class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int num1 = 0;num1<nums.size()-2;num1++){
           if(num1>0 and nums[num1] == nums[num1-1])continue;
           int start = num1+1;
           int end = nums.size()-1;
           int sum = 0-nums[num1];
            while(start < end){
                if(nums[start] + nums[end] == sum){
                    ans.push_back({nums[num1],nums[start],nums[end]});
                    while(start < end and nums[start] == nums[start+1])start++;
                    while(start < end and nums[end] == nums[end-1])end--;
                    ++start;
                    --end;
                }else if(nums[start] + nums[end] < sum){
                    ++start;
                }else --end;
            }
            
        }
        return ans;
    }
};