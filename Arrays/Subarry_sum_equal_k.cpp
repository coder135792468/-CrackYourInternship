class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum =0,ans = 0;
        mp[sum] = 1;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.count(sum-k))ans+=mp[sum-k]; 
            mp[sum]++;
        }
        return ans;
    }
};