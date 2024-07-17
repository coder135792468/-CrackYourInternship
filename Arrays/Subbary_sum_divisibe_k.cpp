class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int res = 0;
       map<int,int> mp;
       mp[0] = 1;
       int sum = 0;
       for(int i= 0;i<nums.size();i++){
         sum=(sum + nums[i] % k + k) % k;
         res+=mp[sum];
         ++mp[sum];
       }
       return res;  
    }
};