class Solution {
public:
    bool isPossible(int mid,vector<int>& nums,int k){
        int cnt = 0, sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            if(sum > mid){
                sum = nums[i];
                ++cnt;
            }
        }
        return cnt >= k;
    }
    int getMaxSum(int mid,vector<int>& nums){
        int sum = 0, cnt = 0 , mx = 0;
        for(int i= 0;i<nums.size();i++){
            sum+=nums[i];
            if(sum >mid){
                sum = nums[i];
            };
            mx = max(mx,sum);
        }
        return mx;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = accumulate(nums.begin(),nums.end(),0);
        while(low <= high){
            int mid = low  + (high-low)/2;
            if(isPossible(mid,nums,k))low = mid + 1;
            else high = mid -1;
        };
        
        return getMaxSum(high + 1,nums);
    }
};