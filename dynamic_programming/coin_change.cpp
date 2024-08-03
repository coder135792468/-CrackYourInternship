class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int j = 1;j<=amount;j++){
            for(int i = 0;i<coins.size();i++){
              if(j >= coins[i]){
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
              }
            }
        }

        return dp[amount] > amount ? -1:dp[amount];
    }
};