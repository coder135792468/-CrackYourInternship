class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k+1,-1e8), sell(k+1);
        for(auto ele:prices){
            for(int j = 1;j<=k;j++){
                 buy[j] = max(buy[j], sell[j-1]  - ele);
                 sell[j] = max(sell[j], buy[j] + ele);
            }
        }
        return sell.back();
    }
};