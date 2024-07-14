class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], sell, profit = 0;
        for(int i = 0;i<prices.size();i++){
            sell = prices[i];
            if(buy > sell)buy = sell;
            if(sell > buy)profit = max(profit,sell-buy);
        }
        
        return profit;
    }
};