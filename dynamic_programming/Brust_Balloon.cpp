class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(303,vector<int>(303));
        for(int i = n;i>=1;i--){
            for(int j = i;j<=n;j++){
                if(i>j)continue;
                for(int k = i;k<=j;k++){
                    int res = nums[i-1]*nums[k]*nums[j+1] 
                               + dp[i][k-1] + dp[k+1][j];
                    dp[i][j] = max(dp[i][j], res);
                }
            }
        }
        return dp[1][n];
    }
};