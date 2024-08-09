class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 100002;
        vector<int> prefix(n,0);
        for(auto ele:nums)prefix[ele]+=ele;

        vector<int> dp(n+1,0);
        dp[1] = prefix[1];
        for(int i= 2;i<n;i++){
            dp[i] = max(prefix[i] + dp[i-2], dp[i-1]);
        };
        return dp[n-1];
    }
};